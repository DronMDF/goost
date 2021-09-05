// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprStreamTest.h"
#include <2out/2out.h>
#include <goost/magma/StMemory.h>
#include "ReprStream.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

ReprStreamTest::ReprStreamTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"Trivial Stream representation",
				make_shared<MatchTest>(
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
