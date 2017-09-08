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
	{0x1122334455667700LLU, 0xffeeddccbbaa9988LLU, 0x7765aeea0c9a7efcLLU, 0xb66cd8887d38e8d7LLU},
	{0x7765aeea0c9a7efcLLU, 0xb66cd8887d38e8d7LLU, 0x7e7b262523280d39LLU, 0x559d8dd7bd06cbfeLLU},
	{0x7e7b262523280d39LLU, 0x559d8dd7bd06cbfeLLU, 0x0d80ef5c5a81c50bLLU, 0x0c3322fed531e463LLU},
	{0x0d80ef5c5a81c50bLLU, 0x0c3322fed531e463LLU, 0xc5df529c13f5acdaLLU, 0x23ae65633f842d29LLU}
};

UP_PARAMETRIZED_TEST(R3412_A11, data)
{
	const SBlock block(BlkRaw(get<0>(data), get<1>(data)));
	UP_ASSERT_EQUAL(block.value(), BlkRaw(get<2>(data), get<3>(data)));
}

UP_SUITE_END()
UP_SUITE_END()
