// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <list>
#include <2out/TestNamed.h>
#include "BlkEncryptedTest.h"
#include "BlkRTest.h"
#include "BlkShiftedTest.h"
#include "BlkXoredTest.h"
#include "BlockTest.h"
#include "ImitTest.h"
#include "KeyDataStringTest.h"
#include "KeyIterTest.h"
#include "LBlockTest.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

kuznyechik::Test::Test()
: tests(
	make_unique<TestNamed>(
		"Kuznyechik tests",
		make_shared<kuznyechik::BlkEncryptedTest>(),
		make_shared<kuznyechik::BlkRTest>(),
		make_shared<kuznyechik::BlkShiftedTest>(),
		make_shared<kuznyechik::BlkXoredTest>(),
		make_shared<kuznyechik::BlockTest>(),
		make_shared<kuznyechik::ImitTest>(),
		make_shared<kuznyechik::KeyDataStringTest>(),
		make_shared<kuznyechik::KeyIterTest>(),
		make_shared<kuznyechik::LBlockTest>()
	)
)
{
}

unique_ptr<const Result> kuznyechik::Test::result() const
{
	return tests->result();
}
