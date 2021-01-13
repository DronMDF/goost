// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ECBSourceTest.h"
#include <goost/magma/ECBSource.h>
#include <goost/magma/LazyKey.h>
#include <test/Hex64Source.h>
#include <test/SourceMatch.h>
#include <test/SourceText.h>

using namespace std;
using namespace oout;
using namespace goost;
using namespace goost::magma;

ECBSourceTest::ECBSourceTest()
: dirty::Test(
	make_shared<NamedTest>(
		"ECB decryption GOST34.12",
		make_shared<SourceText>(
			make_shared<ECBSource>(
				make_shared<Hex64Source>(
					"2b073f0494f372a0"
					"de70e715d3556e48"
					"11d8d9e9eacfbc1e"
					"7c68260996c67efb"
				),
				make_shared<LazyKey>(
					"ffeeddccbbaa99887766554433221100"
					"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
				)
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
