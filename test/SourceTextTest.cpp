// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SourceTextTest.h"
#include <2out/2out.h>

using namespace std;
using namespace oout;

SourceTextTest::SourceTextTest()
	: dirty::Test(
		"SourceText should return Source bytes as hex string",
		make_shared<MatchTest>(
			make_shared<StringText>(""),
			make_shared<EqualMatch>("")
		)
	)
{
}
