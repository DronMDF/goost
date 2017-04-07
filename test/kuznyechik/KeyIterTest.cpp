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

UP_FIXTURE_TEST(R3412_A14_K3, KeyDataFixture)
{
	KeyIter3 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0x228d6aef8cc78c44, 0xdb31485315694343));
}

UP_FIXTURE_TEST(R3412_A14_K4, KeyDataFixture)
{
	KeyIter4 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0x15ebadc40a9ffd04, 0x3d4553d8e9cfec68));
}

UP_FIXTURE_TEST(R3412_A14_K5, KeyDataFixture)
{
	KeyIter5 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0xd3e59246f429f1ac, 0x57646468c44a5e28));
}

UP_FIXTURE_TEST(R3412_A14_K6, KeyDataFixture)
{
	KeyIter6 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0xb532e82834da581b, 0xbd079435165c6432));
}

UP_FIXTURE_TEST(R3412_A14_K7, KeyDataFixture)
{
	KeyIter7 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0x705727265a0098b1, 0x51e640757e8745de));
}

UP_FIXTURE_TEST(R3412_A14_K8, KeyDataFixture)
{
	KeyIter8 key(key_data);
	UP_ASSERT_EQUAL(key.value(), Block(0xd72a91a22286f984, 0x5a7925017b9fdd3e));
}

UP_SUITE_END()
UP_SUITE_END()
