// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRTest.h"
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/BlkRaw.h>
#include <kuznyechik/BlkR.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkRTest::BlkRTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"R3412_A12_1",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<BlkR>(
							make_unique<BlkRaw>(
								0x0000000000000100,
								0x0000000000000000
							)
						)
					),
					"94000000000000000000000000000001"
				)
			),
			make_shared<TestNamed>(
				"R3412_A12_2",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<BlkR>(
							make_unique<BlkRaw>(
								0x0000000000000001,
								0x9400000000000000
							)
						)
					),
					"a5940000000000000000000000000000"
				)
			),
			make_shared<TestNamed>(
				"R3412_A12_3",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<BlkR>(
							make_unique<BlkRaw>(
								0x0000000000000000,
								0xa594000000000000
							)
						)
					),
					"64a59400000000000000000000000000"
				)
			),
			make_shared<TestNamed>(
				"R3412_A12_4",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<BlkR>(
							make_unique<BlkRaw>(
								0x0000000000000000,
								0x64a5940000000000
							)
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
