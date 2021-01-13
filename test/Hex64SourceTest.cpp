// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Hex64SourceTest.h"
#include <2out/2out.h>
#include "Hex64Source.h"
#include "SourceText.h"

using namespace std;
using namespace oout;

Hex64SourceTest::Hex64SourceTest()
	: dirty::Test(
		make_shared<NamedTest>(
			"Hex64Source should should convert GOST representation to byte stream",
			make_shared<SourceText>(
				make_shared<Hex64Source>(
					"92def06b3c130a59"
					"db54c704f8189d20"
				)
			),
			make_shared<EqualMatch>(
				"590a133c6bf0de92"
				"209d18f804c754db"
			)
		)
	)
{
}
