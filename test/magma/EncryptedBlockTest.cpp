#include <upp11.h>
#include <magma/EncryptedBlock.h>
#include <magma/Key.h>

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
		Block({0x10, 0x32, 0x54, 0x76, 0x98, 0xba, 0xdc, 0xfe}),
		key
	);
	UP_ASSERT_EQUAL(eb.value(), Block({0x3d, 0xca, 0xd8, 0xc2, 0xe5, 0x01, 0xe9, 0x4e}));
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
	const EncryptedBlock e(Block(get<0>(data)), key);
	UP_ASSERT_EQUAL(e.value(), Block(get<1>(data)));
}

UP_SUITE_END()
UP_SUITE_END()
