// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkShiftedTest.h"
#include <2out/TestNamed.h>
#include <goost/kuznyechik/BlkShifted.h>
#include <goost/kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkShiftedTest::BlkShiftedTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Shift on 4 bit",
				make_shared<TestBlockEqual>(
					make_unique<BlkShifted>(
						make_shared<BlkString>("1"),
						4
					),
					"00000000000000000000000000000010"
				)
			),
			make_shared<const TestNamed>(
				"Shift over parts",
				make_shared<TestBlockEqual>(
					make_unique<BlkShifted>(
						make_shared<BlkString>("ffffffff00000000"),
						16
					),
					"000000000000ffffffff000000000000"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkShiftedTest::result() const
{
	return tests->result();
}
