// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Imit.h"
#include <iostream>
#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "BlockIterator.h"
#include "DataStream.h"

using namespace std;
using namespace magma;

Imit::Imit(const shared_ptr<const DataStream> &data, const shared_ptr<const Key> &key)
	: data(data), key(key)
{
}

pair<uint32_t, uint32_t> Imit::value() const
{
	auto iter = data->iter();
	auto block = make_shared<const BlkRaw>();

	while (!iter->last()) {
		const auto bv = BlkEncrypted(*block ^ iter->value(), key).value();
		block = make_shared<BlkRaw>(bv.first, bv.second);
		iter = iter->next();
	}


	const auto Rv = BlkEncrypted({}, key).value();
	const BlkRaw R(Rv.first, Rv.second);
	const BlkRaw B(0x1b);
	const auto K1 = ((R.high & 0x80000000) == 0) ? (R << 1) : (R << 1) ^ B;
	if (iter->size() == 8) {
		return BlkEncrypted(*block ^ iter->value() ^ K1, key).value();
	}

	const auto K2 = ((K1.high & 0x80000000) == 0) ? (K1 << 1) : (K1 << 1) ^ B;
	return BlkEncrypted(*block ^ iter->value() ^ K2, key).value();
}
