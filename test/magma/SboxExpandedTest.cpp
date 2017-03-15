#include <upp11.h>
#include <magma/SboxExpanded.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(SboxExpandedTest)

template<int N>
struct TestTab final : public SboxExpanded::Tab {
	uint32_t translate(uint32_t) const override {
		return N;
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

UP_SUITE_END()
