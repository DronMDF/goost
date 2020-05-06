// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxNibble.h"

using namespace std;
using namespace magma;

SboxNibble::SboxNibble(const vector<int> &p0, const vector<int> &p1, const vector<int> &p2,
		const vector<int> &p3, const vector<int> &p4, const vector<int> &p5,
		const vector<int> &p6, const vector<int> &p7)
	: p0(p0), p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6), p7(p7)
{
}

uint32_t SboxNibble::transform(uint32_t value) const
{
	return	transformN(value, p0, 0) |
		transformN(value, p1, 1) |
		transformN(value, p2, 2) |
		transformN(value, p3, 3) |
		transformN(value, p4, 4) |
		transformN(value, p5, 5) |
		transformN(value, p6, 6) |
		transformN(value, p7, 7);
}

uint32_t SboxNibble::transformN(uint32_t value, const vector<int> &p, int nidx) const
{
	const int i = (value >> (nidx * 4)) & 0xf;
	return uint32_t(p[i]) << (nidx * 4);
}
