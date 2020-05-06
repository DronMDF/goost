// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkIncrementedTest.h"
#include <2out/TestNamed.h>
#include <goost/kuznyechik/BlkIncremented.h>
#include <goost/kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkIncrementedTest::BlkIncrementedTest()
	: tests(
		make_shared<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"incremented with overloading",
				make_shared<TestBlockEqual>(
					make_shared<BlkIncremented>(
						make_shared<BlkString>("ffffffffffffffff")
					),
					"00000000000000010000000000000000"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkIncrementedTest::result() const
{
	return tests->result();
}
