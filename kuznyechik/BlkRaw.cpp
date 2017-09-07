// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRaw.h"
#include <iomanip>

using namespace std;
using namespace kuznyechik;

BlkRaw::BlkRaw(uint64_t low, uint64_t high)
	: low(low), high(high)
{
}

BlkRaw::BlkRaw(const pair<uint64_t, uint64_t> &value)
	: BlkRaw(value.first, value.second)
{
}

BlkRaw::BlkRaw(const void * const ptr)
	: BlkRaw(
		reinterpret_cast<const uint64_t * const>(ptr)[0],
		reinterpret_cast<const uint64_t * const>(ptr)[1]
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

bool BlkRaw::operator ==(const BlkRaw &block) const
{
	return low == block.low && high == block.high;
}

BlkRaw BlkRaw::operator <<(int i) const
{
	return {low << i, high << i | low >> (64 - i)};
}

BlkRaw BlkRaw::operator ^(const BlkRaw &b) const
{
	return {low ^ b.low, high ^ b.high};
}

ostream &kuznyechik::operator <<(ostream &os, const BlkRaw &block)
{
	os << hex << setfill('0') << setw(16) << block.high << setw(16) << block.low << dec;
	return os;
}

