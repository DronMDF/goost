// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkSwappedTest.h"
#include <2out/TestNamed.h>
#include <magma/BlkSwapped.h>
#include <magma/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace magma;

BlkSwappedTest::BlkSwappedTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Swap",
				make_shared<TestBlockEqual>(
					make_shared<BlkSwapped>(
						make_shared<BlkString>("aaaaaaaa55555555")
					),
					"55555555aaaaaaaa"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkSwappedTest::result() const
{
	return tests->result();
}
