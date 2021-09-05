// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxTwistedTest.h"
#include <2out/2out.h>
#include <goost/magma/SboxNibble.h>
#include <goost/magma/SboxTwisted.h>
#include "ReprTransformed.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

SboxTwistedTest::SboxTwistedTest()
	: sbox(
		make_shared<SboxTwisted>(
			make_unique<SboxNibble>(
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
	  ),
	  tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"Sbox transformation 1",
				make_shared<MatchTest>(
					make_shared<ReprTransformed>(sbox, 0x87654321 + 0xfedcba98),
					"fdcbc20c"
				)
			),
			make_shared<const NamedTest>(
				"Sbox transformation 2",
				make_shared<MatchTest>(
					make_shared<ReprTransformed>(sbox, 0xfdcbc20c + 0x87654321),
					"7e791a4b"
				)
			),
			make_shared<const NamedTest>(
				"Sbox transformation 3",
				make_shared<MatchTest>(
					make_shared<ReprTransformed>(sbox, 0x7e791a4b + 0xfdcbc20c),
					"c76549ec"
				)
			),
			make_shared<const NamedTest>(
				"Sbox transformation 4",
				make_shared<MatchTest>(
					make_shared<ReprTransformed>(sbox, 0xc76549ec + 0x7e791a4b),
					"9791c849"
				)
			)
		)
	)
{
}

unique_ptr<const Result> SboxTwistedTest::result() const
{
	return tests->result();
}
