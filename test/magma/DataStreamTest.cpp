#include <upp11.h>
#include <magma/Block.h>
#include <magma/BlockIterator.h>
#include <magma/DataStream.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(DataStreamTest)

UP_TEST(R3413_2015_Test)
{
	// Given
	const auto data = make_shared<const DataStream>(
		vector<uint64_t>{
			0x92def06b3c130a59,
			0xdb54c704f8189d20,
			0x4a98fb2e67a8024c,
			0x8912409b17b57e41
		}
	);
	// When
	const auto block0 = data->iter();
	const auto block1 = block0->next();
	const auto block2 = block1->next();
	const auto block3 = block2->next();
	// Then
	UP_ASSERT_EQUAL(block0->value().low, 0x3c130a59);
	UP_ASSERT_EQUAL(block0->value().high, 0x92def06b);
	UP_ASSERT_EQUAL(block1->value().low, 0xf8189d20);
	UP_ASSERT_EQUAL(block1->value().high, 0xdb54c704);
	UP_ASSERT_EQUAL(block2->value().low, 0x67a8024c);
	UP_ASSERT_EQUAL(block2->value().high, 0x4a98fb2e);
	UP_ASSERT_EQUAL(block3->value().low, 0x17b57e41);
	UP_ASSERT_EQUAL(block3->value().high, 0x8912409b);
	UP_ASSERT(block3->last());
}

UP_SUITE_END()
