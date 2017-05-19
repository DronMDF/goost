// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <magma/KeyDataString.h>

using namespace magma;

UP_SUITE_BEGIN(magma)
UP_SUITE_BEGIN(KeyDataStringTest)

UP_TEST(TK26ExampleKey)
{
	KeyDataString kd("ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff");
	UP_ASSERT_EQUAL(kd.key(0), 0xffeeddcc);
	UP_ASSERT_EQUAL(kd.key(1), 0xbbaa9988);
	UP_ASSERT_EQUAL(kd.key(2), 0x77665544);
	UP_ASSERT_EQUAL(kd.key(3), 0x33221100);
	UP_ASSERT_EQUAL(kd.key(4), 0xf0f1f2f3);
	UP_ASSERT_EQUAL(kd.key(5), 0xf4f5f6f7);
	UP_ASSERT_EQUAL(kd.key(6), 0xf8f9fafb);
	UP_ASSERT_EQUAL(kd.key(7), 0xfcfdfeff);
}

UP_SUITE_END()
UP_SUITE_END()
