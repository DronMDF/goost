// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncryptedTest.h"
#include <goost/magma/BlkEncrypted.h>
#include <goost/magma/BlkRaw.h>
#include <goost/magma/LazyKey.h>
#include <test/magma/ReprBlock.h>
#include <test/HexMatch.h>
#include "TestSbox.h"

using namespace std;
using namespace goost;
using namespace goost::magma;
using namespace goost::gost89;

BlkEncryptedTest::BlkEncryptedTest()
: oout::dirty::Test(
	"Block Encryption for gost89",
	make_shared<::magma::ReprBlock>(
		make_shared<BlkEncrypted>(
			make_shared<BlkRaw>(0x04050607, 0x00010203),
			make_shared<LazyKey>(
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
				make_shared<TestSbox>()
			)
		)
	),
	make_shared<HexMatch>("EA4AF215984C8C4B")
)
{
}
