// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "DecryptedBlock.h"
#include "Key.h"

using namespace std;
using namespace magma;

DecryptedBlock::DecryptedBlock(const BlkRaw &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

BlkRaw DecryptedBlock::value() const
{
	const auto rb = key->backward(key->backward(key->backward(key->forward(block)))).value();
	return {rb.second, rb.first};
}
