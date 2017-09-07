// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <kuznyechik/BlkRaw.h>
#include <kuznyechik/Key.h>
#include <kuznyechik/StCTREncrypted.h>
#include <kuznyechik/StMemory.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(StCTREncryptedTest)

UP_TEST(R3413_A121)
{
	const StCTREncrypted stream(
		make_shared<StMemory>(
			vector<uint64_t>{
				0xffeeddccbbaa9988, 0x1122334455667700,
				0x8899aabbcceeff0a, 0x0011223344556677,
				0x99aabbcceeff0a00, 0x1122334455667788,
				0xaabbcceeff0a0011, 0x2233445566778899
			}
		),
		make_shared<Key>(
			"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
		),
		0x1234567890abcef0
	);

	const auto iter1 = stream.iter();
	UP_ASSERT_EQUAL(iter1->value(), BlkRaw(0xd57b5fa240bda1b8, 0xf195d8bec10ed1db));
	const auto iter2 = iter1->next();
	UP_ASSERT_EQUAL(iter2->value(), BlkRaw(0xf33ce4b33c45dee4, 0x85eee733f6a13e5d));
	const auto iter3 = iter2->next();
	UP_ASSERT_EQUAL(iter3->value(), BlkRaw(0xd5e877f13564a3a5, 0xa5eae88be6356ed3));
	const auto iter4 = iter3->next();
	UP_ASSERT_EQUAL(iter4->value(), BlkRaw(0xd1c6d15820bdba73, 0xcb91fab1f20cbab6));
}

UP_SUITE_END()
UP_SUITE_END()
