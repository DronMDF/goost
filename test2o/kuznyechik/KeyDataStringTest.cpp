// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataStringTest.h"
#include <list>
#include <2out/ReprPrintable.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/Block.h>
#include <kuznyechik/KeyDataString.h>
#include "ReprKey.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

KeyDataStringTest::KeyDataStringTest()
: tests(
	make_unique<TestNamed>(
		__func__,
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"High block",
				make_unique<TestEqual>(
					make_unique<ReprKeyHigh>(
						make_unique<KeyDataString>(
							"8899aabbccddeeff0011223344556677"
							"fedcba98765432100123456789abcdef"
						)
					),
					make_unique<ReprPrintable<Block>>(
						Block(0x0011223344556677, 0x8899aabbccddeeff)
					)
				)
			),
			make_unique<TestNamed>(
				"Low block",
				make_unique<TestEqual>(
					make_unique<ReprKeyLow>(
						make_unique<KeyDataString>(
							"8899aabbccddeeff0011223344556677"
							"fedcba98765432100123456789abcdef"
						)
					),
					make_unique<ReprPrintable<Block>>(
						Block(0x0123456789abcdef, 0xfedcba9876543210)
					)
				)
			)
		}
	)
)
{
}

shared_ptr<const Result> KeyDataStringTest::result() const
{
	return tests->result();
}
