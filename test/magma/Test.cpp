// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include <2out/NamedTest.h>
#include "BlkDecryptedTest.h"
#include "BlkEncryptedTest.h"
#include "BlkStringTest.h"
#include "BlkSwappedTest.h"
#include "CFBSinkTest.h"
#include "CFBSourceTest.h"
#include "ECBSinkTest.h"
#include "ECBSourceTest.h"
#include "EncryptionBaseTest.h"
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
using namespace goost::magma;
using namespace magma;
using namespace test::magma;

magma::Test::Test()
	: tests(
		make_unique<NamedTest>(
			"Magma tests",
			make_shared<BlkDecryptedTest>(),
			make_shared<BlkEncryptedTest>(),
			make_shared<BlkStringTest>(),
			make_shared<BlkSwappedTest>(),
			make_shared<CFBSinkTest>(),
			make_shared<CFBSourceTest>(),
			make_shared<ECBSinkTest>(),
			make_shared<ECBSourceTest>(),
			make_shared<EncryptionBaseTest>(),
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

