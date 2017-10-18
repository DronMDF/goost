// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkDecrypted.h"
#include "BlkRaw.h"
#include "Key.h"

using namespace std;
using namespace magma;

BlkDecrypted::BlkDecrypted(const shared_ptr<const Block> &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

pair<uint32_t, uint32_t> BlkDecrypted::value() const
{
	const auto b = block->value();
	const BlkRaw value(b.first, b.second);
	const auto rb = key->backward(key->backward(key->backward(key->forward(value)))).value();
	return {rb.second, rb.first};
}
