// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "LBlockTest.h"
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/LBlock.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

LBlockTest::LBlockTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"R3412_A13_1",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<LBlock>(
							BlkRaw(0x0000000000000000, 0x64a5940000000000)
						)
					),
					"d456584dd0e3e84cc3166e4b7fa2890d"
				)
			),
			make_shared<TestNamed>(
				"R3412_A13_2",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<LBlock>(
							BlkRaw(0xc3166e4b7fa2890d, 0xd456584dd0e3e84c)
						)
					),
					"79d26221b87b584cd42fbc4ffea5de9a"
				)
			),
			make_shared<TestNamed>(
				"R3412_A13_3",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<LBlock>(
							BlkRaw(0xd42fbc4ffea5de9a, 0x79d26221b87b584c)
						)
					),
					"0e93691a0cfc60408b7b68f66b513c13"
				)
			),
			make_shared<TestNamed>(
				"R3412_A13_4",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<LBlock>(
							BlkRaw(0x8b7b68f66b513c13, 0x0e93691a0cfc6040)
						)
					),
					"e6a8094fee0aa204fd97bcb0b44b8580"
				)
			)
		)
	)
{
}

unique_ptr<const Result> LBlockTest::result() const
{
	return tests->result();
}
