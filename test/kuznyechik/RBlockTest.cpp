// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <kuznyechik/RBlock.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(RBlockTest)

const vector<tuple<uint64_t, uint64_t, uint64_t, uint64_t>> data = {
	{0x0000000000000100LU, 0x0000000000000000LU, 0x0000000000000001LU, 0x9400000000000000LU},
	{0x0000000000000001LU, 0x9400000000000000LU, 0x0000000000000000LU, 0xa594000000000000LU},
	{0x0000000000000000LU, 0xa594000000000000LU, 0x0000000000000000LU, 0x64a5940000000000LU},
	{0x0000000000000000LU, 0x64a5940000000000LU, 0x0000000000000000LU, 0x0d64a59400000000LU}
};

UP_PARAMETRIZED_TEST(R3412_A12, data)
{
	const RBlock block(BlkRaw(get<0>(data), get<1>(data)));
	UP_ASSERT_EQUAL(block.value(), BlkRaw(get<2>(data), get<3>(data)));
}

UP_SUITE_END()
UP_SUITE_END()
