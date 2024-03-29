// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkDecryptedTest.h"
#include <2out/NamedTest.h>
#include <goost/magma/BlkDecrypted.h>
#include <goost/magma/BlkString.h>
#include <goost/magma/LazyKey.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

BlkDecryptedTest::BlkDecryptedTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"R3412_A25",
				make_shared<TestBlockEqual>(
					make_shared<BlkDecrypted>(
						make_shared<BlkString>("4ee901e5c2d8ca3d"),
						make_shared<LazyKey>(
							"ffeeddccbbaa99887766554433221100"
							"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
						)
					),
					make_shared<BlkString>("fedcba9876543210")
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkDecryptedTest::result() const
{
	return tests->result();
}
