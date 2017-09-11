// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <list>
#include <2out/TestNamed.h>
#include "BlkEncryptedTest.h"
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
		list<shared_ptr<const oout::Test>>{
			make_unique<kuznyechik::BlkEncryptedTest>(),
			make_unique<kuznyechik::BlkShiftedTest>(),
			make_unique<kuznyechik::BlkXoredTest>(),
			make_unique<kuznyechik::BlockTest>(),
			make_unique<kuznyechik::ImitTest>(),
			make_unique<kuznyechik::KeyDataStringTest>(),
			make_unique<kuznyechik::KeyIterTest>(),
			make_unique<kuznyechik::LBlockTest>()
		}
	)
)
{
}

unique_ptr<const Result> kuznyechik::Test::result() const
{
	return tests->result();
}
