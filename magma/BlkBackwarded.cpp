// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkBackwarded.h"
#include "BlkRaw.h"
#include "Key.h"

using namespace std;
using namespace magma;

BlkBackwarded::BlkBackwarded(const shared_ptr<const Block> &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

pair<uint32_t, uint32_t> BlkBackwarded::value() const
{
	return key->backward(BlkRaw(block)).value();
}
