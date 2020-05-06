// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataStringTest.h"
#include <2out/TestNamed.h>
#include <goost/kuznyechik/KeyDataString.h>
#include "BlkKeyData.h"
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

KeyDataStringTest::KeyDataStringTest()
	: key_data(
		make_shared<KeyDataString>(
			"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
		)
	  ),
	  tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"High block",
				make_shared<TestBlockEqual>(
					make_shared<BlkKeyDataHigh>(key_data),
					"8899aabbccddeeff0011223344556677"
				)
			),
			make_shared<TestNamed>(
				"Low block",
				make_shared<TestBlockEqual>(
					make_shared<BlkKeyDataLow>(key_data),
					"fedcba98765432100123456789abcdef"
				)
			)
		)
	)
{
}

unique_ptr<const Result> KeyDataStringTest::result() const
{
	return tests->result();
}
