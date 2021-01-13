// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkIncremented.h"
#include <limits>

using namespace std;
using namespace goost::kuznyechik;

BlkIncremented::BlkIncremented(const shared_ptr<const Block> &block)
	: block(block)
{
}

pair<uint64_t, uint64_t> BlkIncremented::value() const
{
	const auto value = block->value();
	if (value.first == numeric_limits<uint64_t>::max()) {
		return {0, value.second + 1};
	}
	return {value.first + 1, value.second};
}
