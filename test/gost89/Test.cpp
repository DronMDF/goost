// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include "BlkEncryptedTest.h"
#include "CFBSinkTest.h"
#include "CFBSourceTest.h"

using namespace std;
using namespace oout;
using namespace goost;
using namespace goost::gost89;

gost89::Test::Test()
	: dirty::Test(
		"Gost89 tests",
		make_shared<BlkEncryptedTest>(),
		make_shared<CFBSinkTest>(),
		make_shared<CFBSourceTest>()
	)
{
}
