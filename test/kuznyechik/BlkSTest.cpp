// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkSTest.h"
#include <2out/TestNamed.h>
#include <goost/kuznyechik/BlkS.h>
#include <goost/kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkSTest::BlkSTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"R3412_A11_1",
				make_shared<TestBlockEqual>(
					make_unique<BlkS>(
						make_shared<BlkString>(
							"ffeeddccbbaa99881122334455667700"
						)
					),
					"b66cd8887d38e8d77765aeea0c9a7efc"
				)
			),
			make_shared<TestNamed>(
				"R3412_A11_2",
				make_shared<TestBlockEqual>(
					make_unique<BlkS>(
						make_shared<BlkString>(
							"b66cd8887d38e8d77765aeea0c9a7efc"
						)
					),
					"559d8dd7bd06cbfe7e7b262523280d39"
				)
			),
			make_shared<TestNamed>(
				"R3412_A11_3",
				make_shared<TestBlockEqual>(
					make_unique<BlkS>(
						make_shared<BlkString>(
							"559d8dd7bd06cbfe7e7b262523280d39"
						)
					),
					"0c3322fed531e4630d80ef5c5a81c50b"
				)
			),
			make_shared<TestNamed>(
				"R3412_A11_4",
				make_shared<TestBlockEqual>(
					make_unique<BlkS>(
						make_shared<BlkString>(
							"0c3322fed531e4630d80ef5c5a81c50b"
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
