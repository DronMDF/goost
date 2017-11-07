// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ImitTest.h"
#include <2out/TestNamed.h>
#include <magma/Imit.h>
#include <magma/Key.h>
#include <magma/StMemory.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace magma;

ImitTest::ImitTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"R3413_A262_Test",
				make_shared<TestBlockEqual>(
					make_shared<Imit>(
						make_shared<StMemory>(
							vector<uint64_t>{
								0x92def06b3c130a59,
								0xdb54c704f8189d20,
								0x4a98fb2e67a8024c,
								0x8912409b17b57e41
							}
						),
						make_shared<Key>(
							"ffeeddccbbaa99887766554433221100"
							"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
						)
					),
					"154e72102030c5bb"
				)
			)
		)
	)
{
}

unique_ptr<const Result> ImitTest::result() const
{
	return tests->result();
}
