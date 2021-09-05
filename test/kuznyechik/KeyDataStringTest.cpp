// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataStringTest.h"
#include <2out/NamedTest.h>
#include <goost/kuznyechik/KeyDataString.h>
#include "BlkKeyData.h"
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

KeyDataStringTest::KeyDataStringTest()
	: key_data(
		make_shared<KeyDataString>(
			"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
		)
	  ),
	  tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<NamedTest>(
				"High block",
				make_shared<TestBlockEqual>(
					make_shared<BlkKeyDataHigh>(key_data),
					"8899aabbccddeeff0011223344556677"
				)
			),
			make_shared<NamedTest>(
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
