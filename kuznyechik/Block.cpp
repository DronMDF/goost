#include "Block.h"
#include <iomanip>

using namespace std;
using namespace kuznyechik;

Block::Block(uint64_t low, uint64_t high)
	: low(low), high(high)
{
}

bool Block::operator ==(const Block &block) const
{
	return low == block.low && high == block.high;
}

ostream &kuznyechik::operator <<(ostream &os, const Block &block)
{
	os << hex << setfill('0') << setw(16) << block.high << setw(16) << block.low << dec;
	return os;
}

