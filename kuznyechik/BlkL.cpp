// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkL.h"
#include "BlkR.h"

using namespace std;
using namespace kuznyechik;

BlkL::BlkL(const shared_ptr<const Block> &block)
	: block(block)
{
}

pair<uint64_t, uint64_t> BlkL::value() const
{
	return transform(block, 16)->value();
}

shared_ptr<const Block> BlkL::transform(const shared_ptr<const Block> &b, int n) const
{
	if (n == 0) {
		return b;
	}

	return transform(make_unique<BlkR>(BlkRaw(b)), n - 1);
}
