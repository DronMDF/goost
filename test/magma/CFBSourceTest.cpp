// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSourceTest.h"
#include <goost/magma/CFBSource.h>
#include <goost/magma/LazyKey.h>
#include <test/Hex64Source.h>
#include <test/SourceMatch.h>
#include <test/SourceText.h>

using namespace std;
using namespace oout;
using namespace goost;
using namespace goost::magma;

CFBSourceTest::CFBSourceTest()
: dirty::Test(
	make_shared<NamedTest>(
		"CFBSource should decrypt GOST34.12 magma example",
		make_shared<SourceText>(
			make_shared<CFBSource>(
				make_shared<Hex64Source>(
					"db37e0e266903c83"
					"0d46644c1f9a089c"
					"24bdd2035315d38b"
					"bcc0321421075505"
				),
				make_shared<LazyKey>(
					"ffeeddccbbaa99887766554433221100"
					"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
				),
				0x1234567890abcdef,
				0x234567890abcdef1
			)
		),
		make_shared<SourceMatch>(
			make_shared<Hex64Source>(
				"92def06b3c130a59"
				"db54c704f8189d20"
				"4a98fb2e67a8024c"
				"8912409b17b57e41"
			)
		)
	)
)
{
}
