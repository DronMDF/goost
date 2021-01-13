// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRaw.h"

using namespace std;
using namespace goost::kuznyechik;

BlkRaw::BlkRaw(uint64_t low, uint64_t high)
	: low(low), high(high)
{
}

BlkRaw::BlkRaw(const pair<uint64_t, uint64_t> &value)
	: BlkRaw(value.first, value.second)
{
}

BlkRaw::BlkRaw(const shared_ptr<const Block> &block)
	: BlkRaw(block->value())
{
}

BlkRaw::BlkRaw(const void * const ptr)
	: BlkRaw(
		reinterpret_cast<const uint64_t *>(ptr)[0],
		reinterpret_cast<const uint64_t *>(ptr)[1]
	)
{
}

BlkRaw::BlkRaw(uint64_t low)
	: BlkRaw(low, 0)
{
}

BlkRaw::BlkRaw()
	: BlkRaw(uint64_t(0))
{
}

pair<uint64_t, uint64_t> BlkRaw::value() const
{
	return {low, high};
}
