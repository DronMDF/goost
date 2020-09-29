// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncryptedTest.h"
#include <limits>
#include <goost/Source.h>
#include <goost/gost89/CFBSink.h>
#include <goost/magma/BlkEncrypted.h>
#include <goost/magma/BlkRaw.h>
#include <goost/magma/Key.h>
#include <goost/magma/SboxByte.h>
#include <test/magma/ReprBlock.h>

using namespace std;
using namespace oout;
using namespace goost;
using namespace goost::magma;
using namespace goost::gost89;

BlkEncryptedTest::BlkEncryptedTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Block Encryption for gost89",
		make_shared<ReprBlock>(
			make_shared<BlkEncrypted>(
				make_shared<BlkRaw>(0x04050607, 0x00010203),
				make_shared<Key>(
					vector<uint32_t>{
						0xE0F67504,
						0xFAFB3850,
						0x90C3C7D2,
						0x3DCAB3ED,
						0x42124715,
						0x8A1EAE91,
						0x9ECD792F,
						0xBDEFBCD2
					},
					make_shared<SboxByte>(
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
		make_shared<EqualMatch>("EA4AF215984C8C4B")
	)
)
{
}
