// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <2out/TestNamed.h>
#include "BlkDecryptedTest.h"
#include "BlkEncryptedTest.h"
#include "BlkStringTest.h"
#include "ImitTest.h"
#include "ReprStreamTest.h"

using namespace std;
using namespace oout;
using namespace magma;

magma::Test::Test()
	: tests(
		make_unique<TestNamed>(
			"Magma tests",
			make_shared<BlkDecryptedTest>(),
			make_shared<BlkEncryptedTest>(),
			make_shared<BlkStringTest>(),
			make_shared<ImitTest>(),
			make_shared<ReprStreamTest>()
		)
	)
{
}

unique_ptr<const Result> magma::Test::result() const
{
	return tests->result();
}

