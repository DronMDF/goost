// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkR.h"
#include <array>
#include <cstring>
#include "BlkRaw.h"

using namespace std;
using namespace kuznyechik;

BlkR::BlkR(const shared_ptr<const Block> &block)
	: block(block)
{
}

// @todo #82:32min Use predefined gmul tab for speedup kuznyechik alg
//  Calculation is slower solution.
uint8_t BlkR::gmul(uint8_t a, uint8_t b) const
{
	uint8_t p = 0;
	for (int counter = 0; counter < 8; counter++) {
		if ((b & 1) == 1) {
			p ^= a;
		}

		uint8_t hi_bit_set = (a & 0x80);
		a <<= 1;

		if (hi_bit_set == 0x80) {
			a ^= 0x1c3; /* x^8 + x^7 + x^6 + x + 1 */
		}
		b >>= 1;
	}

	return p;
}

pair<uint64_t, uint64_t> BlkR::value() const
{
	constexpr int k[16] = {
		1, 148, 32, 133, 16, 194, 192, 1, 251, 1, 192, 194, 16, 133, 32, 148
	};
	const auto value = block->value();
	array<uint8_t, 17> data;
	memcpy(&data[0], &value.first, sizeof(value.first));
	memcpy(&data[8], &value.second, sizeof(value.second));
	int sum = 0;
	for (size_t i = 0; i < Block::size; i++) {
		sum ^= gmul(data[i], k[i]);
	}
	data[16] = sum;
	return BlkRaw(&data[1]).value();
}
