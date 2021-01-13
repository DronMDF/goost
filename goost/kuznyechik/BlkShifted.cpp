// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkShifted.h"

using namespace std;
using namespace goost::kuznyechik;

BlkShifted::BlkShifted(const shared_ptr<const Block> &block, int n)
	: block(block), n(n)
{
}

pair<uint64_t, uint64_t> BlkShifted::value() const
{
	const auto value = block->value();
	return {value.first << n, value.second << n | value.first >> (64 - n)};
}
