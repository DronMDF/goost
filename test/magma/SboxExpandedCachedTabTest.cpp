#include <upp11.h>
#include <magma/SboxExpandedCachedTab.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(SboxExpandedCachedTabTest)

class TestTab final : public SboxExpanded::Tab {
public:
	TestTab(int * const counter)
		: counter(counter)
	{
	}
	array<uint32_t, 256> table() const override {
		++*counter;
		return {};
	}
private:
	int * const counter;
};

UP_TEST(TestTabCounter)
{
	int counter = 0;
	const TestTab tab(&counter);
	UP_ASSERT_EQUAL(tab.table()[0], tab.table()[0]);
	UP_ASSERT_EQUAL(counter, 2);
};

UP_TEST(CallInnerTabOnlyOnce)
{
	int counter = 0;
	const SboxExpandedCachedTab tab(make_unique<TestTab>(&counter));
	UP_ASSERT_EQUAL(tab.table()[0], tab.table()[0]);
	UP_ASSERT_EQUAL(counter, 1);
};

UP_SUITE_END()
