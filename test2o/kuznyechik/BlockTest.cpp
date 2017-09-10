// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockTest.h"
#include <list>
#include <2out/ReprPrintable.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/BlkRaw.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

// @todo #182 Rename BlockTest to BlkRawTest
BlockTest::BlockTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"ByteOrder",
				make_shared<TestEqual>(
					make_unique<ReprPrintable<BlkRaw>>(
						BlkRaw(1)
					),
					"00000000000000000000000000000001"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlockTest::result() const
{
	return tests->result();
}
