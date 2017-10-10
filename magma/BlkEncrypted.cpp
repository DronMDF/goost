// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncrypted.h"
#include "Key.h"

using namespace std;
using namespace magma;

BlkEncrypted::BlkEncrypted(const BlkRaw &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

pair<uint32_t, uint32_t> BlkEncrypted::value() const
{
	const auto rb = key->backward(key->forward(key->forward(key->forward(block)))).value();
	return {rb.second, rb.first};
}
