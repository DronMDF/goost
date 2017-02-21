#include <upp11.h>
#include <magma/KeyDataNative.h>

using namespace magma;

UP_SUITE_BEGIN(KeyDataNativeTest)

UP_TEST(SimpleKey)
{
	KeyDataNative kd({
		0xE0F67504U,
		0xFAFB3850U,
		0x90C3C7D2U,
		0x3DCAB3EDU,
		0x42124715U,
		0x8A1EAE91U,
		0x9ECD792FU,
		0xBDEFBCD2U
	});
	UP_ASSERT_EQUAL(kd.key(0), 0xE0F67504);
	UP_ASSERT_EQUAL(kd.key(1), 0xFAFB3850);
	UP_ASSERT_EQUAL(kd.key(2), 0x90C3C7D2);
	UP_ASSERT_EQUAL(kd.key(3), 0x3DCAB3ED);
	UP_ASSERT_EQUAL(kd.key(4), 0x42124715);
	UP_ASSERT_EQUAL(kd.key(5), 0x8A1EAE91);
	UP_ASSERT_EQUAL(kd.key(6), 0x9ECD792F);
	UP_ASSERT_EQUAL(kd.key(7), 0xBDEFBCD2);
}

UP_SUITE_END()
