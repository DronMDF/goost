#include <upp11.h>
#include <kuznyechik/RBlock.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(RBlockTest)

const vector<tuple<uint64_t, uint64_t, uint64_t, uint64_t>> data = {
	{0x0000000000000100, 0x0000000000000000, 0x0000000000000001, 0x9400000000000000},
	{0x0000000000000001, 0x9400000000000000, 0x0000000000000000, 0xa594000000000000},
	{0x0000000000000000, 0xa594000000000000, 0x0000000000000000, 0x64a5940000000000},
	{0x0000000000000000, 0x64a5940000000000, 0x0000000000000000, 0x0d64a59400000000}
};

UP_PARAMETRIZED_TEST(R3413_A12, data)
{
	const RBlock block(Block(get<0>(data), get<1>(data)));
	UP_ASSERT_EQUAL(block.value(), Block(get<2>(data), get<3>(data)));
}

UP_SUITE_END()
UP_SUITE_END()
