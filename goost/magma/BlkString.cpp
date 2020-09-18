// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkString.h"

using namespace std;
using namespace goost::magma;

BlkString::BlkString(const string &block)
	: block(block)
{
}

pair<uint32_t, uint32_t> BlkString::value() const
{
	auto value = block;
	while (value.size() < Block::size * 2) {
		value.insert(0, 1, '0');
	}
	size_t pos;
	return {stoull(string(value, 8, 8), &pos, 16), stoull(string(value, 0, 8), &pos, 16)};
}
