// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkXoredTest.h"
#include <2out/TestNamed.h>
#include <kuznyechik/BlkString.h>
#include <kuznyechik/BlkXored.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkXoredTest::BlkXoredTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Xor",
				make_shared<TestBlockEqual>(
					make_unique<BlkXored>(
						make_shared<BlkString>(
							"0000000000000000ffffffffffffffff"
						),
						make_shared<BlkString>(
							"ffffffffffffffff0000000000000000"
						)
					),
					"ffffffffffffffffffffffffffffffff"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkXoredTest::result() const
{
	return tests->result();
}

