#include <upp11.h>
#include <magma/SboxNibble.h>
#include <magma/SboxTwisted.h>
#include <magma/Key.h>
#include <magma/KeyDataString.h>

using namespace std;
using namespace magma;


UP_SUITE_BEGIN(KeyTest)

struct KeyTestFixture {
	const shared_ptr<const Sbox> sbox = make_shared<const SboxTwisted>(
		make_shared<const SboxNibble>(
			vector<int>{12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1},
			vector<int>{6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15},
			vector<int>{11, 3, 5, 8, 2, 15, 10, 13, 14, 1, 7, 4, 12, 9, 6, 0},
			vector<int>{12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11},
			vector<int>{7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12},
			vector<int>{5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0},
			vector<int>{8, 14, 2 , 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7},
			vector<int>{1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12, 11, 2}
		)
	);
};

UP_FIXTURE_TEST(A24ExampleTest, KeyTestFixture)
{
	const Key key("ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff", sbox);
	const auto result = key.encrypt({0x10, 0x32, 0x54, 0x76, 0x98, 0xba, 0xdc, 0xfe});
	UP_ASSERT_EQUAL(result, vector<uint8_t>{0x3d, 0xca, 0xd8, 0xc2, 0xe5, 0x01, 0xe9, 0x4e});
}

UP_FIXTURE_TEST(A25ExampleTest, KeyTestFixture)
{
	const Key key("ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff", sbox);
	const auto result = key.decrypt({0x3d, 0xca, 0xd8, 0xc2, 0xe5, 0x01, 0xe9, 0x4e});
	UP_ASSERT_EQUAL(result, vector<uint8_t>{0x10, 0x32, 0x54, 0x76, 0x98, 0xba, 0xdc, 0xfe});
}

UP_SUITE_END()
