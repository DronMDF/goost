// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Imit.h"
#include "Block.h"
#include "EncryptedBlock.h"
#include "Iterator.h"
#include "Stream.h"

using namespace std;
using namespace kuznyechik;

Imit::Imit(const shared_ptr<const Stream> &data, const shared_ptr<const Key> &key)
	: data(data), key(key)
{
}

Block Imit::value() const
{
	auto iter = data->iter();
	auto block = make_shared<const Block>();

	while (!iter->last()) {
		block = make_shared<const Block>(
			EncryptedBlock(*block ^ iter->value(), key).value()
		);
		iter = iter->next();
	}

	const auto R = EncryptedBlock({}, key).value();
	const Block B(0x87);
	const auto K1 = ((R.high & 0x8000000000000000) == 0) ? (R << 1) : (R << 1) ^ B;
	if (iter->size() == 16) {
		return EncryptedBlock(*block ^ iter->value() ^ K1, key).value();
	}

	const auto K2 = ((K1.high & 0x8000000000000000) == 0) ? (K1 << 1) : (K1 << 1) ^ B;
	return EncryptedBlock(*block ^ iter->value() ^ K2, key).value();
}
