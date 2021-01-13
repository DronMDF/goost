// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxNibbleTest.h"
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <goost/magma/SboxNibble.h>
#include "ReprTransformed.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

SboxNibbleTest::SboxNibbleTest()
	: sbox(
		make_shared<SboxNibble>(
			vector<int>{12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1},
			vector<int>{6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15},
			vector<int>{11, 3, 5, 8, 2, 15, 10, 13, 14, 1, 7, 4, 12, 9, 6, 0},
			vector<int>{12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11},
			vector<int>{7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12},
			vector<int>{5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0},
			vector<int>{8, 14, 2 , 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7},
			vector<int>{1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12, 11, 2}
		)
	  ),
	  tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Sbox transformation 1",
				make_shared<TestEqual>(
					make_shared<ReprTransformed>(sbox, 0xfdb97531),
					"2a196f34"
				)
			),
			make_shared<const TestNamed>(
				"Sbox transformation 2",
				make_shared<TestEqual>(
					make_shared<ReprTransformed>(sbox, 0x2a196f34),
					"ebd9f03a"
				)
			),
			make_shared<const TestNamed>(
				"Sbox transformation 3",
				make_shared<TestEqual>(
					make_shared<ReprTransformed>(sbox, 0xebd9f03a),
					"b039bb3d"
				)
			),
			make_shared<const TestNamed>(
				"Sbox transformation 4",
				make_shared<TestEqual>(
					make_shared<ReprTransformed>(sbox, 0xb039bb3d),
					"68695433"
				)
			)
		)
	)
{
}

unique_ptr<const Result> SboxNibbleTest::result() const
{
	return tests->result();
}
