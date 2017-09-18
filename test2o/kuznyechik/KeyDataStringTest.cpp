// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataStringTest.h"
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/BlkRaw.h>
#include <kuznyechik/KeyDataString.h>
#include "ReprBlock.h"
#include "ReprKeyData.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

KeyDataStringTest::KeyDataStringTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"High block",
				make_shared<TestEqual>(
					make_unique<ReprKeyDataHigh>(
						make_unique<KeyDataString>(
							"8899aabbccddeeff0011223344556677"
							"fedcba98765432100123456789abcdef"
						)
					),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x0011223344556677,
							0x8899aabbccddeeff
						)
					)
				)
			),
			make_shared<TestNamed>(
				"Low block",
				make_shared<TestEqual>(
					make_unique<ReprKeyDataLow>(
						make_unique<KeyDataString>(
							"8899aabbccddeeff0011223344556677"
							"fedcba98765432100123456789abcdef"
						)
					),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x0123456789abcdef,
							0xfedcba9876543210
						)
					)
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
