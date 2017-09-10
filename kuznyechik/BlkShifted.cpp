// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkShifted.h"

using namespace std;
using namespace kuznyechik;

BlkShifted::BlkShifted(const std::shared_ptr<const Block> &block, int n)
	: block(block), n(n)
{
}

pair<uint64_t, uint64_t> BlkShifted::value() const
{
	const auto value = block->value();
	return {value.first << n, value.second << n | value.first >> (64 - n)};
}
