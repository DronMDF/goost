#include <upp11.h>
#include <magma/KeyCachedData.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(magma)
UP_SUITE_BEGIN(KeyCachedDataTest)

class TestKeyData final : public KeyData {
public:
	explicit TestKeyData(array<int, 8> * const counter)
		: counter(counter)
	{
	}

	uint32_t key(int index) const override {
		counter->at(index)++;
		return index * 12345;
	}
private:
	TestKeyData(const TestKeyData &) = delete;
	TestKeyData operator = (const TestKeyData &) = delete;

	array<int, 8> * const counter;
};

UP_TEST(InvokeOriginOnce)
{
	// Given
	array<int, 8> counter = {{0, 0, 0, 0, 0, 0, 0, 0}};
	KeyCachedData kd(make_unique<const TestKeyData>(&counter));
	// When
	for (int i = 0; i < 8; i++) {
		UP_ASSERT_EQUAL(kd.key(i), i * 12345);
	}
	for (int i = 0; i < 8; i++) {
		UP_ASSERT_EQUAL(kd.key(i), i * 12345);
	}
	// Then
	for (auto const &c: counter) {
		UP_ASSERT_EQUAL(c, 1);
	}
}

UP_SUITE_END()
UP_SUITE_END()
