// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <kuznyechik/LBlock.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(LBlockTest)

const vector<tuple<uint64_t, uint64_t, uint64_t, uint64_t>> data = {
	{0x0000000000000000, 0x64a5940000000000, 0xc3166e4b7fa2890d, 0xd456584dd0e3e84c},
	{0xc3166e4b7fa2890d, 0xd456584dd0e3e84c, 0xd42fbc4ffea5de9a, 0x79d26221b87b584c},
	{0xd42fbc4ffea5de9a, 0x79d26221b87b584c, 0x8b7b68f66b513c13, 0x0e93691a0cfc6040},
	{0x8b7b68f66b513c13, 0x0e93691a0cfc6040, 0xfd97bcb0b44b8580, 0xe6a8094fee0aa204}
};

UP_PARAMETRIZED_TEST(R3412_A13, data)
{
	const LBlock block(Block(get<0>(data), get<1>(data)));
	UP_ASSERT_EQUAL(block.value(), Block(get<2>(data), get<3>(data)));
}

UP_SUITE_END()
UP_SUITE_END()
