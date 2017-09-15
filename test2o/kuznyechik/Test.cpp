// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <list>
#include <2out/TestNamed.h>
#include "BlkEncryptedTest.h"
#include "BlkLTest.h"
#include "BlkRawTest.h"
#include "BlkRTest.h"
#include "BlkShiftedTest.h"
#include "BlkSTest.h"
#include "BlkXoredTest.h"
#include "ImitTest.h"
#include "KeyDataStringTest.h"
#include "KeyIterTest.h"
#include "StCTREncryptedTest.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

kuznyechik::Test::Test()
	: tests(
		make_unique<TestNamed>(
			"Kuznyechik tests",
			make_shared<BlkEncryptedTest>(),
			make_shared<BlkLTest>(),
			make_shared<BlkRawTest>(),
			make_shared<BlkRTest>(),
			make_shared<BlkShiftedTest>(),
			make_shared<BlkSTest>(),
			make_shared<BlkXoredTest>(),
			make_shared<ImitTest>(),
			make_shared<KeyDataStringTest>(),
			make_shared<KeyIterTest>(),
			make_shared<StCTREncryptedTest>()
		)
	)
{
}

unique_ptr<const Result> kuznyechik::Test::result() const
{
	return tests->result();
}
