// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <magma/EncryptedBlock.h>
#include <magma/Key.h>
#include <magma/SboxTwisted.h>
#include <magma/SboxByte.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(magma)
UP_SUITE_BEGIN(EncryptedBlockTest)

struct KeyFixture {
	const shared_ptr<const Key> key = make_shared<Key>(
		"ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
	);
};

UP_FIXTURE_TEST(R3412_A24_Test, KeyFixture)
{
	const EncryptedBlock eb(
		BlkRaw({0x10, 0x32, 0x54, 0x76, 0x98, 0xba, 0xdc, 0xfe}),
		key
	);
	UP_ASSERT_EQUAL(eb.value(), BlkRaw({0x3d, 0xca, 0xd8, 0xc2, 0xe5, 0x01, 0xe9, 0x4e}));
}

const vector<pair<uint64_t, uint64_t>> data = {
	{0x92def06b3c130a59, 0x2b073f0494f372a0},
	{0xf053f8006cebef80, 0xc89ed814fd5e18e9},
	{0x8206233a9af61aa5, 0xf739b18d34289b00},
	{0x216e6a2561cff165, 0x154e72102030c5bb}
};

// Strange is A2.6.2 uses Encrypt alg... Should be 2 rounds....
// But tests is successefull.
UP_FIXTURE_PARAMETRIZED_TEST(R3413_A262_Test, KeyFixture, data)
{
	const EncryptedBlock e(BlkRaw(get<0>(data)), key);
	UP_ASSERT_EQUAL(e.value(), BlkRaw(get<1>(data)));
}

const vector<pair<uint64_t, uint64_t>> old_data = {
	{0x0001020304050607, 0xEA4AF215984C8C4B},
	{0x08090a0b0c0d0e0f, 0xD12EBCB30957C31E}
};

UP_PARAMETRIZED_TEST(TestSboxByteEncryption, old_data)
{
	const EncryptedBlock e(
		BlkRaw(get<0>(old_data)),
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
	);

	UP_ASSERT_EQUAL(e.value(), BlkRaw(get<1>(old_data)));
}

UP_SUITE_END()
UP_SUITE_END()
