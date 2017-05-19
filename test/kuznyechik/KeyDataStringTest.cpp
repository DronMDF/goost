// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <kuznyechik/Block.h>
#include <kuznyechik/KeyDataString.h>

using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(KeyDataStringTest)

UP_TEST(R3412_A14)
{
	KeyDataString kd("8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef");
	UP_ASSERT_EQUAL(kd.high(), Block(0x0011223344556677, 0x8899aabbccddeeff));
	UP_ASSERT_EQUAL(kd.low(), Block(0x0123456789abcdef, 0xfedcba9876543210));
}

UP_SUITE_END()
UP_SUITE_END()
