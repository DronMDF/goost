// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkForwarded.h"
#include "BlkRaw.h"
#include "Key.h"

using namespace std;
using namespace magma;

BlkForwarded::BlkForwarded(const shared_ptr<const Block> &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

pair<uint32_t, uint32_t> BlkForwarded::value() const
{
	const auto value = block->value();
	uint32_t a = value.first;
	uint32_t b = value.second;

	b ^= key->transform(a, 0);
	a ^= key->transform(b, 1);
	b ^= key->transform(a, 2);
	a ^= key->transform(b, 3);
	b ^= key->transform(a, 4);
	a ^= key->transform(b, 5);
	b ^= key->transform(a, 6);
	a ^= key->transform(b, 7);

	return {a, b};
}
