// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkBackwarded.h"
#include "LazyKey.h"

using namespace std;
using namespace goost::magma;

BlkBackwarded::BlkBackwarded(const shared_ptr<const Block> &block, const shared_ptr<const LazyKey> &key)
	: block(block), key(key)
{
}

pair<uint32_t, uint32_t> BlkBackwarded::value() const
{
	const auto value = block->value();
	uint32_t a = value.first;
	uint32_t b = value.second;

	b ^= key->transform(a, 7);
	a ^= key->transform(b, 6);
	b ^= key->transform(a, 5);
	a ^= key->transform(b, 4);
	b ^= key->transform(a, 3);
	a ^= key->transform(b, 2);
	b ^= key->transform(a, 1);
	a ^= key->transform(b, 0);

	return {a, b};
}
