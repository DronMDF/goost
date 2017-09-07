// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <kuznyechik/SBlock.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(SBlockTest)

const vector<tuple<uint64_t, uint64_t, uint64_t, uint64_t>> data = {
	{0x1122334455667700, 0xffeeddccbbaa9988, 0x7765aeea0c9a7efc, 0xb66cd8887d38e8d7},
	{0x7765aeea0c9a7efc, 0xb66cd8887d38e8d7, 0x7e7b262523280d39, 0x559d8dd7bd06cbfe},
	{0x7e7b262523280d39, 0x559d8dd7bd06cbfe, 0x0d80ef5c5a81c50b, 0x0c3322fed531e463},
	{0x0d80ef5c5a81c50b, 0x0c3322fed531e463, 0xc5df529c13f5acda, 0x23ae65633f842d29}
};

UP_PARAMETRIZED_TEST(R3412_A11, data)
{
	const SBlock block(BlkRaw(get<0>(data), get<1>(data)));
	UP_ASSERT_EQUAL(block.value(), BlkRaw(get<2>(data), get<3>(data)));
}

UP_SUITE_END()
UP_SUITE_END()
