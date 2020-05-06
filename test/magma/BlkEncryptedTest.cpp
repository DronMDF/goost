// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncryptedTest.h"
#include <2out/TestNamed.h>
#include <goost/magma/BlkEncrypted.h>
#include <goost/magma/BlkRaw.h>
#include <goost/magma/Key.h>
#include <goost/magma/SboxByte.h>
#include <goost/magma/SboxTwisted.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace magma;

BlkEncryptedTest::BlkEncryptedTest()
	: key1(
		make_shared<Key>(
			"ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
		)
	  ),
	  key2(
		make_shared<Key>(
			vector<uint32_t>{
				0xE0F67504, 0xFAFB3850, 0x90C3C7D2, 0x3DCAB3ED,
				0x42124715, 0x8A1EAE91, 0x9ECD792F, 0xBDEFBCD2
			},
			make_shared<SboxTwisted>(
				make_unique<SboxByte>(
					vector<uint8_t>{
						0xc4, 0xed, 0x83, 0xc9, 0x92, 0x98, 0xfe, 0x6b,
						0xff, 0xbe, 0x65, 0x5c, 0xe5, 0x2c, 0xb9, 0x20,
						0x89, 0x57, 0x16, 0xb3, 0x11, 0xf3, 0x98, 0x06,
						0x30, 0x79, 0xc0, 0x97, 0xa8, 0x1a, 0x5d, 0xd5,
						0x2e, 0x01, 0xda, 0x34, 0x73, 0xd5, 0x3b, 0xe8,
						0x4b, 0xc2, 0x77, 0x7e, 0xdc, 0x64, 0xac, 0xaf,
						0x6d, 0xa6, 0x02, 0xf1, 0x07, 0x4f, 0xe1, 0x4a,
						0xba, 0x30, 0x2f, 0x12, 0x56, 0x8b, 0x44, 0x8d
					}
				)
			)
		)
	  ),
	  tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"R3412_A24",
				make_shared<TestBlockEqual>(
					make_shared<BlkEncrypted>(
						make_shared<BlkRaw>(
							vector<uint8_t>{
								0x10, 0x32, 0x54, 0x76,
								0x98, 0xba, 0xdc, 0xfe
							}
						),
						key1
					),
					"4ee901e5c2d8ca3d"
				)
			),
			make_shared<const TestNamed>(
				"R3412_A262_1",
				make_shared<TestBlockEqual>(
					make_shared<BlkEncrypted>(
						make_shared<BlkRaw>(0x92def06b3c130a59),
						key1
					),
					"2b073f0494f372a0"
				)
			),
			make_shared<const TestNamed>(
				"R3412_A262_2",
				make_shared<TestBlockEqual>(
					make_shared<BlkEncrypted>(
						make_shared<BlkRaw>(0xf053f8006cebef80),
						key1
					),
					"c89ed814fd5e18e9"
				)
			),
			make_shared<const TestNamed>(
				"R3412_A262_3",
				make_shared<TestBlockEqual>(
					make_shared<BlkEncrypted>(
						make_shared<BlkRaw>(0x8206233a9af61aa5),
						key1
					),
					"f739b18d34289b00"
				)
			),
			make_shared<const TestNamed>(
				"R3412_A262_4",
				make_shared<TestBlockEqual>(
					make_shared<BlkEncrypted>(
						make_shared<BlkRaw>(0x216e6a2561cff165),
						key1
					),
					"154e72102030c5bb"
				)
			),
			make_shared<const TestNamed>(
				"TestSboxbyteEncryption #1",
				make_shared<TestBlockEqual>(
					make_shared<BlkEncrypted>(
						make_shared<BlkRaw>(0x0001020304050607),
						key2
					),
					"ea4af215984c8c4b"
				)
			),
			make_shared<const TestNamed>(
				"TestSboxbyteEncryption #2",
				make_shared<TestBlockEqual>(
					make_shared<BlkEncrypted>(
						make_shared<BlkRaw>(0x08090a0b0c0d0e0f),
						key2
					),
					"d12ebcb30957c31e"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkEncryptedTest::result() const
{
	return tests->result();
}
