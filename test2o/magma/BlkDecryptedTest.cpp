// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkDecryptedTest.h"
#include <2out/TestNamed.h>
#include <magma/BlkDecrypted.h>
#include <magma/Key.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace magma;

BlkDecryptedTest::BlkDecryptedTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"R3412_A25",
				make_shared<TestBlockEqual>(
					make_shared<BlkDecrypted>(
						BlkRaw({
							0x3d, 0xca, 0xd8, 0xc2,
							0xe5, 0x01, 0xe9, 0x4e
						}),
						make_shared<Key>(
							"ffeeddccbbaa99887766554433221100"
							"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
						)
					),
					make_shared<BlkRaw>(
						vector<uint8_t>{
							0x10, 0x32, 0x54, 0x76,
							0x98, 0xba, 0xdc, 0xfe
						}
					)
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
