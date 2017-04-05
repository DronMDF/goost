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
		Block(0x1122334455667700, 0xffeeddccbbaa9988),
		key
	);
	UP_ASSERT_EQUAL(block.value(), Block(0x7f679d90bebc2430, 0x5a468d42b9d4edcd));
}

UP_SUITE_END()
UP_SUITE_END()
