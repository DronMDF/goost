// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRaw.h"
#include <iomanip>

using namespace std;
using namespace magma;

BlkRaw::BlkRaw()
	: BlkRaw(0LU)
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

BlkRaw::BlkRaw(uint32_t low, uint32_t high)
	: low(low), high(high)
{
}

bool BlkRaw::operator ==(const BlkRaw &block) const
{
	return low == block.low && high == block.high;
}

BlkRaw BlkRaw::operator <<(int i) const
{
	return {low << i, high << i | low >> (32 - i)};
}

BlkRaw BlkRaw::operator ^(const BlkRaw &b) const
{
	return {low ^ b.low, high ^ b.high};
}

ostream &magma::operator <<(ostream &os, const BlkRaw &block)
{
	os << hex << setfill('0') << setw(8) << block.high << setw(8) << block.low << dec;
	return os;
}