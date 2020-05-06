// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkStringTest.h"
#include <2out/TestNamed.h>
#include <goost/magma/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace magma;

BlkStringTest::BlkStringTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Expansion",
				make_shared<TestBlockEqual>(
					make_shared<BlkString>("1"),
					"0000000000000001"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkStringTest::result() const
{
	return tests->result();
}
