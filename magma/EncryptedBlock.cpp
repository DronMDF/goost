// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EncryptedBlock.h"
#include "Key.h"

using namespace std;
using namespace magma;

EncryptedBlock::EncryptedBlock(const BlkRaw &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

BlkRaw EncryptedBlock::value() const
{
	const auto rb = key->backward(key->forward(key->forward(key->forward(block))));
	return BlkRaw(rb.high, rb.low);
}
