// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkSTest.h"
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/SBlock.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkSTest::BlkSTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"R3412_A11_1",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<SBlock>(
							BlkRaw(0x1122334455667700, 0xffeeddccbbaa9988)
						)
					),
					"b66cd8887d38e8d77765aeea0c9a7efc"
				)
			),
			make_shared<TestNamed>(
				"R3412_A11_2",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<SBlock>(
							BlkRaw(0x7765aeea0c9a7efc, 0xb66cd8887d38e8d7)
						)
					),
					"559d8dd7bd06cbfe7e7b262523280d39"
				)
			),
			make_shared<TestNamed>(
				"R3412_A11_3",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<SBlock>(
							BlkRaw(0x7e7b262523280d39, 0x559d8dd7bd06cbfe)
						)
					),
					"0c3322fed531e4630d80ef5c5a81c50b"
				)
			),
			make_shared<TestNamed>(
				"R3412_A11_4",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<SBlock>(
							BlkRaw(0x0d80ef5c5a81c50b, 0x0c3322fed531e463)
						)
					),
					"23ae65633f842d29c5df529c13f5acda"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkSTest::result() const
{
	return tests->result();
}
