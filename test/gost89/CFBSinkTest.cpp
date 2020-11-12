// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSinkTest.h"
#include <limits>
#include <goost/Source.h>
#include <goost/gost89/CFBSink.h>
#include <goost/magma/Key.h>
#include <test/Hex64Source.h>
#include <test/SourceMatch.h>
#include <test/TestSink.h>
#include <test/TestSinkText.h>
#include "TestSbox.h"

using namespace std;
using namespace oout;
using namespace goost;
using namespace goost::magma;
using namespace goost::gost89;

CFBSinkTest::CFBSinkTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Cipher feedback encryption by GOST-89 example",
		make_shared<TestSinkText>(
			make_shared<CFBSink>(
				make_shared<TestSink>(),
				make_shared<Key>(
					vector<uint32_t>{
						0xE0F67504,
						0xFAFB3850,
						0x90C3C7D2,
						0x3DCAB3ED,
						0x42124715,
						0x8A1EAE91,
						0x9ECD792F,
						0xBDEFBCD2
					},
					make_shared<TestSbox>()
				),
				0x47E3A8FFC3A7802A
			),
			make_shared<Hex64Source>("33333333CCCCCCCC" "CCCCCCCC33333333")
		),
		make_shared<SourceMatch>(
			make_shared<Hex64Source>("4B64BD1043224C3B" "0FAA6CD95548EB99")
		)
	)
)
{
}
