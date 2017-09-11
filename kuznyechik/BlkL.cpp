// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkL.h"
#include "RBlock.h"

using namespace std;
using namespace kuznyechik;

BlkL::BlkL(const BlkRaw &block)
	: block(block)
{
}

pair<uint64_t, uint64_t> BlkL::value() const
{
	return transform(block, 16).value();
}

BlkRaw BlkL::transform(const BlkRaw &b, int n) const
{
	if (n == 0) {
		return b;
	}

	return transform(BlkRaw(RBlock(b).value()), n - 1);
}
