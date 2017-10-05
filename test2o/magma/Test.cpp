// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <2out/TestNamed.h>
#include "BlkStringTest.h"

using namespace std;
using namespace oout;
using namespace magma;

magma::Test::Test()
	: tests(
		make_unique<TestNamed>(
			"Magma tests",
			make_shared<BlkStringTest>()
		)
	)
{
}

unique_ptr<const Result> magma::Test::result() const
{
	return tests->result();
}

