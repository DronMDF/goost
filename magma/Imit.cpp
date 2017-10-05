// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Imit.h"
#include <iostream>
#include "BlkRaw.h"
#include "BlockIterator.h"
#include "DataStream.h"
#include "EncryptedBlock.h"

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
		block = make_shared<const BlkRaw>(
			EncryptedBlock(*block ^ iter->value(), key).value()
		);
		iter = iter->next();
	}

	const auto R = EncryptedBlock({}, key).value();
	const BlkRaw B(0x1b);
	const auto K1 = ((R.high & 0x80000000) == 0) ? (R << 1) : (R << 1) ^ B;
	if (iter->size() == 8) {
		const auto rv1 = EncryptedBlock(*block ^ iter->value() ^ K1, key).value();
		return {rv1.low, rv1.high};
	}

	const auto K2 = ((K1.high & 0x80000000) == 0) ? (K1 << 1) : (K1 << 1) ^ B;
	const auto rv2 = EncryptedBlock(*block ^ iter->value() ^ K2, key).value();
	return {rv2.low, rv2.high};
}
