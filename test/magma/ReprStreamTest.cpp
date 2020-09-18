// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprStreamTest.h"
#include <2out/TestNamed.h>
#include <2out/TestEqual.h>
#include <goost/magma/StMemory.h>
#include "ReprStream.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

ReprStreamTest::ReprStreamTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Trivial Stream representation",
				make_shared<TestEqual>(
					make_shared<ReprStream>(
						make_shared<StMemory>(
							vector<uint64_t>{
								0xffeeddccbbaa9988,
								0x1122334455667700
							}
						)
					),
					"8899aabbccddeeff0077665544332211"
				)
			)
		)
	)
{
}

unique_ptr<const Result> ReprStreamTest::result() const
{
	return tests->result();
}
