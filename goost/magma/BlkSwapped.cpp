// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkSwapped.h"

using namespace std;
using namespace goost::magma;

BlkSwapped::BlkSwapped(const shared_ptr<const Block> &block)
	: block(block)
{
}

pair<uint32_t, uint32_t> BlkSwapped::value() const
{
	const auto value = block->value();
	return {value.second, value.first};
}
