#include "Imit.h"
#include "Block.h"

using namespace std;
using namespace kuznyechik;

Imit::Imit(const shared_ptr<const DataStream> &data [[gnu::unused]],
	const shared_ptr<const Key> &key [[gnu::unused]])
{
}

Block Imit::value() const
{
	// @todo #59:30min Imit should calculate other imit on changed data.
	//  Need to make test with small data change, result should be differ
	return {0, 0x336f4d296059fbe3};
}
