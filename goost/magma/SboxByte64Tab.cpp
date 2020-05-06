// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxByte64Tab.h"

using namespace std;
using namespace magma;

SboxByte64Tab::SboxByte64Tab(const vector<uint8_t> &uz, int offset)
	: uz(uz), offset(offset)
{
}

uint32_t SboxByte64Tab::translate(int index) const
{
	return (uz[((index >> 4) & 0xf) * 4 + offset] & 0xf0)
		+ (uz[(index & 0xf) * 4 + offset] & 0x0f);
}
