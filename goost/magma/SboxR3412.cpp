// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxR3412.h"
#include <vector>
#include "SboxTwisted.h"
#include "SboxNibble.h"

using namespace std;
using namespace goost::magma;

SboxR3412::SboxR3412()
	: sbox(
		make_unique<const SboxTwisted>(
			make_unique<const SboxNibble>(
				vector<int>{12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1},
				vector<int>{6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15},
				vector<int>{11, 3, 5, 8, 2, 15, 10, 13, 14, 1, 7, 4, 12, 9, 6, 0},
				vector<int>{12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11},
				vector<int>{7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12},
				vector<int>{5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0},
				vector<int>{8, 14, 2 , 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7},
				vector<int>{1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12, 11, 2}
			)
		)
	)
{
}

uint32_t SboxR3412::transform(uint32_t value) const
{
	return sbox->transform(value);
}
