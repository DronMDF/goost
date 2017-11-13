// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <2out/TestNamed.h>
#include "BlkDecryptedTest.h"
#include "BlkEncryptedTest.h"
#include "BlkStringTest.h"
#include "BlkSwappedTest.h"
#include "ImitTest.h"
#include "KeyCachedDataTest.h"
#include "KeyDataNativeTest.h"
#include "KeyDataStringTest.h"
#include "ReprStreamTest.h"
#include "SboxNibbleTest.h"
#include "SboxTwistedTest.h"
#include "StMemoryTest.h"

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
			make_shared<BlkSwappedTest>(),
			make_shared<ImitTest>(),
			make_shared<KeyCachedDataTest>(),
			make_shared<KeyDataNativeTest>(),
			make_shared<KeyDataStringTest>(),
			make_shared<ReprStreamTest>(),
			make_shared<SboxNibbleTest>(),
			make_shared<SboxTwistedTest>(),
			make_shared<StMemoryTest>()
		)
	)
{
}

unique_ptr<const Result> magma::Test::result() const
{
	return tests->result();
}
