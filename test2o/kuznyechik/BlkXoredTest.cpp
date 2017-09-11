// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkXoredTest.h"
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/BlkRaw.h>
#include <kuznyechik/BlkXored.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkXoredTest::BlkXoredTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Xor",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(
						make_unique<BlkXored>(
							make_unique<BlkRaw>(0xffffffffffffffff, 0),
							make_unique<BlkRaw>(0, 0xffffffffffffffff)
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

