// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkIterKey.h"
#include "BlkL.h"
#include "BlkRaw.h"
#include "BlkS.h"
#include "BlkXored.h"

using namespace std;
using namespace goost::kuznyechik;

BlkIterKey::BlkIterKey(
	const shared_ptr<const Block> &ka,
	const shared_ptr<const Block> &kb,
	int c1, int c2
) : ka(ka), kb(kb), c1(c1), c2(c2)
{
}

pair<uint64_t, uint64_t> BlkIterKey::value() const
{
	return generate(kb, ka, c1)->value();
}

shared_ptr<const Block> BlkIterKey::generate(
	const shared_ptr<const Block> &a,
	const shared_ptr<const Block> &b,
	int i
) const
{
	if (i > c2) {
		return b;
	}

	const auto cn = make_shared<BlkL>(make_unique<BlkRaw>(i));
	return generate(
		b,
		make_shared<BlkXored>(
			a,
			make_unique<BlkL>(make_unique<BlkS>(make_unique<BlkXored>(b, cn)))
		),
		i + 1
	);
}
