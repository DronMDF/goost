// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRTest.h"
#include <2out/TestNamed.h>
#include <kuznyechik/BlkR.h>
#include <kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkRTest::BlkRTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"R3412_A12_1",
				make_shared<TestBlockEqual>(
					make_unique<BlkR>(
						make_unique<BlkString>("100")
					),
					"94000000000000000000000000000001"
				)
			),
			make_shared<TestNamed>(
				"R3412_A12_2",
				make_shared<TestBlockEqual>(
					make_unique<BlkR>(
						make_unique<BlkString>(
							"94000000000000000000000000000001"
						)
					),
					"a5940000000000000000000000000000"
				)
			),
			make_shared<TestNamed>(
				"R3412_A12_3",
				make_shared<TestBlockEqual>(
					make_unique<BlkR>(
						make_unique<BlkString>(
							"a5940000000000000000000000000000"
						)
					),
					"64a59400000000000000000000000000"
				)
			),
			make_shared<TestNamed>(
				"R3412_A12_4",
				make_shared<TestBlockEqual>(
					make_unique<BlkR>(
						make_unique<BlkString>(
							"64a59400000000000000000000000000"
						)
					),
					"0d64a594000000000000000000000000"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkRTest::result() const
{
	return tests->result();
}
