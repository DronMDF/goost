#include "upp11.h"
#include <magma/Block.h>
#include <magma/DataStream.h>
#include <magma/Imit.h>
#include <magma/Key.h>
#include <magma/SboxExpanded.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(ImitTest)

UP_TEST(R3413_A262_Test)
{
	const auto key = make_shared<const Key>(
		"ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
	);
	const auto data = make_shared<const DataStream>(
		vector<uint64_t>{
			0x92def06b3c130a59,
			0xdb54c704f8189d20,
			0x4a98fb2e67a8024c,
			0x8912409b17b57e41
		}
	);
	const Imit imit(data, key);
	UP_ASSERT_EQUAL(imit.value().high, 0x154e7210);
}

UP_TEST(BenchmarkTest)
{
	const auto key = make_shared<const Key>(
		"ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
	);
	const auto data = make_shared<const DataStream>(
		vector<uint64_t>(10000000U / sizeof(uint64_t))
	);
	const Imit imit(data, key);
	UP_ASSERT_EQUAL(imit.value().high, 3801817732);
}

UP_TEST(BenchmarkTestExpanded)
{
	const auto key = make_shared<const Key>(
		"ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff",
		make_shared<SboxExpanded>(
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
	const auto data = make_shared<const DataStream>(
		vector<uint64_t>(10000000U / sizeof(uint64_t))
	);
	const Imit imit(data, key);
	UP_ASSERT_EQUAL(imit.value().high, 3801817732);
}

UP_SUITE_END()
