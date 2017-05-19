// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <kuznyechik/EncryptedBlock.h>
#include <kuznyechik/Key.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(EncryptedBlockTest)

struct KeyFixture {
	const shared_ptr<const Key> key = make_shared<Key>(
		"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
	);
};

UP_FIXTURE_TEST(R3412_A15, KeyFixture)
{
	const EncryptedBlock block(
		Block(0xffeeddccbbaa9988, 0x1122334455667700),
		key
	);
	UP_ASSERT_EQUAL(block.value(), Block(0x5a468d42b9d4edcd, 0x7f679d90bebc2430));
}

const vector<tuple<uint64_t, uint64_t, uint64_t, uint64_t>> data = {
	{0xffeeddccbbaa9988, 0x1122334455667700, 0x5a468d42b9d4edcd, 0x7f679d90bebc2430},
	{0x8899aabbcceeff0a, 0x0011223344556677, 0x285452d76718d08b, 0xb429912c6e0032f9},
	{0x99aabbcceeff0a00, 0x1122334455667788, 0xf3f5a5313bd4b157, 0xf0ca33549d247cee},
	{0xaabbcceeff0a0011, 0x2233445566778899, 0x3a02c4c5aa8ada98, 0xd0b09ccde830b9eb}
};

UP_FIXTURE_PARAMETRIZED_TEST(R3413_A11, KeyFixture, data)
{
	const EncryptedBlock block(Block(get<0>(data), get<1>(data)), key);
	UP_ASSERT_EQUAL(block.value(), Block(get<2>(data), get<3>(data)));
}

UP_SUITE_END()
UP_SUITE_END()
