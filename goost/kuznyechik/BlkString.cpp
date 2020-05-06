// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkString.h"

using namespace std;
using namespace kuznyechik;

BlkString::BlkString(const string &block)
	: block(block)
{
}

pair<uint64_t, uint64_t> BlkString::value() const
{
	auto value = block;
	while (value.size() < sizeof(uint64_t) * 2 * 2) {
		value.insert(0, 1, '0');
	}
	size_t pos;
	return {stoull(string(value, 16, 16), &pos, 16), stoull(string(value, 0, 16), &pos, 16)};
}
