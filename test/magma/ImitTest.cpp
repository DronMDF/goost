// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ImitTest.h"
#include <2out/NamedTest.h>
#include <goost/magma/Imit.h>
#include <goost/magma/LazyKey.h>
#include <test/Hex64Source.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

ImitTest::ImitTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"R3413_A262_Test",
				make_shared<TestBlockEqual>(
					make_shared<Imit>(
						make_shared<Hex64Source>(
							"92def06b3c130a59"
							"db54c704f8189d20"
							"4a98fb2e67a8024c"
							"8912409b17b57e41"
						),
						make_shared<LazyKey>(
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
