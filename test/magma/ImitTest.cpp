#include "upp11.h"
#include <magma/Block.h>
#include <magma/DataStream.h>
#include <magma/Imit.h>
#include <magma/Key.h>

using namespace std;
using namespace magma;

UP_SUITE_BEGIN(magma)
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

UP_TEST(Benchmark10M)
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

UP_SUITE_END()
UP_SUITE_END()
