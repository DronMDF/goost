// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <list>
#include <2out/TestNamed.h>
#include "BlockTest.h"
#include "KeyDataStringTest.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

kuznyechik::Test::Test()
: tests(
	make_unique<TestNamed>(
		"Kuznyechik tests",
		list<shared_ptr<const oout::Test>>{
			make_unique<kuznyechik::BlockTest>(),
			make_unique<kuznyechik::KeyDataStringTest>()
		}
	)
)
{
}

shared_ptr<const Result> kuznyechik::Test::result() const
{
	return tests->result();
}
