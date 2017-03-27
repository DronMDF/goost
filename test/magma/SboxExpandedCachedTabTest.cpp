#include <upp11.h>
#include <magma/SboxExpandedCachedTab.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(magma)
UP_SUITE_BEGIN(SboxExpandedCachedTabTest)

class TestTab final : public SboxExpanded::Tab {
public:
	TestTab(int * const counter)
		: counter(counter)
	{
	}
	uint32_t translate(int) const override {
		++*counter;
		return 0;
	}
private:
	int * const counter;
};

UP_TEST(TestTabCounter)
{
	int counter = 0;
	const TestTab tab(&counter);
	UP_ASSERT_EQUAL(tab.translate(0), tab.translate(0));
	UP_ASSERT_EQUAL(counter, 2);
};

UP_TEST(CallInnerTabOnlyOnce)
{
	int counter = 0;
	const SboxExpandedCachedTab tab(make_unique<TestTab>(&counter));
	UP_ASSERT_EQUAL(tab.translate(0), tab.translate(0));
	// Cacher gathered all table
	UP_ASSERT_EQUAL(counter, 256);
};

UP_SUITE_END()
UP_SUITE_END()
