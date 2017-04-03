#include "upp11.h"
#include <kuznyechik/Block.h>
#include <kuznyechik/DataStream.h>
#include <kuznyechik/Imit.h>
#include <kuznyechik/Key.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(ImitTest)

UP_TEST(R3413_A162)
{
	const auto key = make_shared<const Key>(
		"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
	);
	const auto data = make_shared<const DataStream>(
		vector<uint64_t>{
			0x1122334455667700, 0xffeeddccbbaa9988,
			0x0011223344556677, 0x8899aabbcceeff0a,
			0x1122334455667788, 0x99aabbcceeff0a00,
			0x2233445566778899, 0xaabbcceeff0a0011
		}
	);
	const Imit imit(data, key);
	UP_ASSERT_EQUAL(imit.value().high, 0x336f4d296059fbe3);
}

UP_SUITE_END()
UP_SUITE_END()
