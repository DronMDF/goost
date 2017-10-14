// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <magma/BlkDecrypted.h>
#include <magma/Key.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(magma)
UP_SUITE_BEGIN(DecryptedBlockTest)

UP_TEST(R3412_A25_Test)
{
	const auto value = BlkDecrypted(
		BlkRaw({0x3d, 0xca, 0xd8, 0xc2, 0xe5, 0x01, 0xe9, 0x4e}),
		make_shared<Key>(
			"ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
		)
	).value();
	UP_ASSERT_EQUAL(
		BlkRaw(value.first, value.second),
		BlkRaw({0x10, 0x32, 0x54, 0x76, 0x98, 0xba, 0xdc, 0xfe})
	);
}

UP_SUITE_END()
UP_SUITE_END()

