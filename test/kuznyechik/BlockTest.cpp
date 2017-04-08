#include <upp11.h>
#include <kuznyechik/Block.h>

using namespace std;
using namespace kuznyechik;

UP_SUITE_BEGIN(kuznyechik)
UP_SUITE_BEGIN(BlockTest)

UP_TEST(ByteOrder)
{
	Block block(1);
	ostringstream os;
	os << block;
	UP_ASSERT_EQUAL(os.str(), "00000000000000000000000000000001");
}

UP_SUITE_END()
UP_SUITE_END()
