// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkIncrementedTest.h"
#include <2out/NamedTest.h>
#include <goost/kuznyechik/BlkIncremented.h>
#include <goost/kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkIncrementedTest::BlkIncrementedTest()
	: tests(
		make_shared<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
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
