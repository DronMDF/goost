#include <upp11.h>
#include <kuznyechik/Block.h>
#include <kuznyechik/KeyDataString.h>
#include <kuznyechik/KeyIter.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(KeyIterTest)

struct KeyDataFixture {
	const shared_ptr<const Key::Data> key_data = make_shared<KeyDataString>(
		"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
	);
};

UP_FIXTURE_TEST(R3412_A14_K1, KeyDataFixture)
{
	KeyIter1 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0x0011223344556677, 0x8899aabbccddeeff));
}

UP_FIXTURE_TEST(R3412_A14_K2, KeyDataFixture)
{
	KeyIter2 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0x0123456789abcdef, 0xfedcba9876543210));
}

UP_SUITE_END()
UP_SUITE_END()
