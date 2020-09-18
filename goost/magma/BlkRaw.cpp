// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRaw.h"
#include <iomanip>

using namespace std;
using namespace goost::magma;

BlkRaw::BlkRaw(uint32_t low, uint32_t high)
	: low(low), high(high)
{
}

BlkRaw::BlkRaw(const pair<uint32_t, uint32_t> &value)
	: BlkRaw(value.first, value.second)
{
}

BlkRaw::BlkRaw(const shared_ptr<const Block> &block)
	: BlkRaw(block->value())
{
}

BlkRaw::BlkRaw(uint64_t block)
	: BlkRaw(block, block >> 32)
{
}

BlkRaw::BlkRaw(const vector<uint8_t> &block)
	: BlkRaw(
		reinterpret_cast<const uint32_t *>(&block[0])[0],
		reinterpret_cast<const uint32_t *>(&block[0])[1]
	  )
{
}

BlkRaw::BlkRaw(const void *ptr)
	: BlkRaw(
		reinterpret_cast<const uint32_t *>(ptr)[0],
		reinterpret_cast<const uint32_t *>(ptr)[1]
	  )
{
}

BlkRaw::BlkRaw()
	: BlkRaw(0LU)
{
}

pair<uint32_t, uint32_t> BlkRaw::value() const
{
	return {low, high};
}
