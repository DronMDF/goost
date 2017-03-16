#include <upp11.h>
#include <magma/SboxExpanded.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(SboxExpandedTest)

template<int N>
struct TestTab final : public SboxExpanded::Tab {
	array<uint32_t, 256> table() const override {
		array<uint32_t, 256> tab;
		tab.fill(N);
		return tab;
	}
};

UP_TEST(TransformTest)
{
	SboxExpanded sbox{
		make_unique<TestTab<0x11>>(),
		make_unique<TestTab<0x2200>>(),
		make_unique<TestTab<0x330000>>(),
		make_unique<TestTab<0x44000000>>()
	};

	UP_ASSERT_EQUAL(sbox.transform(0x12345678), 0x44332211);
}

UP_TEST(R3412Test)
{
	SboxExpanded sbox(
		{12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1},
		{6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15},
		{11, 3, 5, 8, 2, 15, 10, 13, 14, 1, 7, 4, 12, 9, 6, 0},
		{12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11},
		{7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12},
		{5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0},
		{8, 14, 2 , 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7},
		{1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12, 11, 2}
	);
	UP_ASSERT_EQUAL(sbox.transform(0x87654321 + 0xfedcba98), 0xfdcbc20c);
	UP_ASSERT_EQUAL(sbox.transform(0xfdcbc20c + 0x87654321), 0x7e791a4b);
	UP_ASSERT_EQUAL(sbox.transform(0x7e791a4b + 0xfdcbc20c), 0xc76549ec);
	UP_ASSERT_EQUAL(sbox.transform(0xc76549ec + 0x7e791a4b), 0x9791c849);
}

UP_SUITE_END()
