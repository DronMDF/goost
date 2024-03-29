// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkShiftedTest.h"
#include <2out/NamedTest.h>
#include <goost/kuznyechik/BlkShifted.h>
#include <goost/kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkShiftedTest::BlkShiftedTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"Shift on 4 bit",
				make_shared<TestBlockEqual>(
					make_unique<BlkShifted>(
						make_shared<BlkString>("1"),
						4
					),
					"00000000000000000000000000000010"
				)
			),
			make_shared<const NamedTest>(
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
