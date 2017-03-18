#include <upp11.h>
#include <magma/SboxExpandedCachedTab.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(SboxExpandedCachedTabTest)

struct TestTab final : public SboxExpanded::Tab {
	static int counter;
	TestTab() {
	}
	array<uint32_t, 256> table() const override {
		counter++;
		return {};
	}
};

int TestTab::counter;

UP_TEST(TestTabCounter)
{
	TestTab::counter = 0;
	const TestTab tab;
	UP_ASSERT_EQUAL(tab.table()[0], tab.table()[0]);
	UP_ASSERT_EQUAL(TestTab::counter, 2);
};

UP_TEST(CallInnerTabOnlyOnce)
{
	TestTab::counter = 0;
	const SboxExpandedCachedTab tab(make_unique<TestTab>());
	UP_ASSERT_EQUAL(tab.table()[0], tab.table()[0]);
	UP_ASSERT_EQUAL(TestTab::counter, 1);
};

UP_SUITE_END()
