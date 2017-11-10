// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Imit.h"
#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "BlkXored.h"
#include "Iterator.h"
#include "Stream.h"

using namespace std;
using namespace magma;

Imit::Imit(const shared_ptr<const Stream> &data, const shared_ptr<const Key> &key)
	: data(data), key(key)
{
}

pair<uint32_t, uint32_t> Imit::value() const
{
	auto iter = data->iter();
	auto block = make_shared<const BlkRaw>();

	while (!iter->last()) {
		const auto bv = BlkEncrypted(BlkRaw(BlkXored(block, iter).value()), key).value();
		block = make_shared<BlkRaw>(bv);
		iter = iter->next();
	}

	const auto R = BlkRaw(BlkEncrypted({}, key).value());
	const auto B = make_shared<BlkRaw>(0x1b);
	const auto K1 = make_shared<BlkXored>(
		make_shared<BlkRaw>((R << 1).value()),
		(R.value().second & 0x80000000) == 0 ?  make_shared<BlkRaw>() : B
	);
	if (iter->size() == 8) {
		return BlkEncrypted(BlkRaw(BlkXored(block, iter, K1).value()), key).value();
	}

	const auto K2 = make_shared<BlkXored>(
		make_shared<BlkRaw>((BlkRaw(K1) << 1).value()),
		(K1->value().second & 0x80000000) == 0 ?  make_shared<BlkRaw>() : B
	);
	return BlkEncrypted(BlkRaw(BlkXored(block, iter, K2).value()), key).value();
}
