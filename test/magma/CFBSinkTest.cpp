// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSinkTest.h"
#include <goost/Source.h>
#include <goost/magma/CFBSink.h>
#include <goost/magma/LazyKey.h>
#include <test/Hex64Source.h>
#include <test/SourceMatch.h>
#include <test/TestSink.h>
#include <test/TestSinkText.h>

using namespace std;
using namespace oout;
using namespace goost;
using namespace goost::magma;

CFBSinkTest::CFBSinkTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Cipher feedback encryption by GOST-34.13 example",
		make_shared<TestSinkText>(
			make_shared<CFBSink>(
				make_shared<TestSink>(),
				make_shared<LazyKey>(
					"ffeeddccbbaa99887766554433221100"
					"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
				),
				0x1234567890abcdef,
				0x234567890abcdef1
			),
			make_shared<Hex64Source>(
				"92def06b3c130a59"
				"db54c704f8189d20"
				"4a98fb2e67a8024c"
				"8912409b17b57e41"
			)
		),
		make_shared<SourceMatch>(
			make_shared<Hex64Source>(
				"db37e0e266903c83"
				"0d46644c1f9a089c"
				"24bdd2035315d38b"
				"bcc0321421075505"
			)
		)
	)
)
{
}
