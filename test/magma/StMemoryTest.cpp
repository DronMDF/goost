// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StMemoryTest.h"
#include <2out/2out.h>
#include <goost/magma/StMemory.h>
#include "ReprStream.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

StMemoryTest::StMemoryTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"StMemory simple test",
				make_shared<MatchTest>(
					make_shared<ReprStream>(
						make_shared<StMemory>(
							vector<uint64_t>{
								0x92def06b3c130a59,
								0xdb54c704f8189d20,
								0x4a98fb2e67a8024c,
								0x8912409b17b57e41
							}
						)
					),
					"590a133c6bf0de92209d18f804c754db"
					"4c02a8672efb984a417eb5179b401289"
				)
			)
		)
	)
{
}

unique_ptr<const Result> StMemoryTest::result() const
{
	return tests->result();
}

