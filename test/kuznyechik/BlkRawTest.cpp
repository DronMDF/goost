// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRawTest.h"
#include <2out/TestNamed.h>
#include <goost/kuznyechik/BlkRaw.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkRawTest::BlkRawTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"ByteOrder",
				make_shared<TestBlockEqual>(
					make_unique<BlkRaw>(1),
					"00000000000000000000000000000001"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkRawTest::result() const
{
	return tests->result();
}
