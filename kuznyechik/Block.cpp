#include "Block.h"
#include <iomanip>

using namespace std;
using namespace kuznyechik;

Block::Block()
	: Block(uint64_t(0))
{
}

Block::Block(uint64_t low)
	: Block(low, 0)
{
}

Block::Block(const void * const ptr)
	: Block(
		reinterpret_cast<const uint64_t * const>(ptr)[0],
		reinterpret_cast<const uint64_t * const>(ptr)[1]
	)
{
}

Block::Block(uint64_t low, uint64_t high)
	: low(low), high(high)
{
}

bool Block::operator ==(const Block &block) const
{
	return low == block.low && high == block.high;
}

Block Block::operator <<(int i) const
{
	return {low << i, high << i | low >> (64 - i)};
}

Block Block::operator ^(const Block &b) const
{
	return {low ^ b.low, high ^ b.high};
}

ostream &kuznyechik::operator <<(ostream &os, const Block &block)
{
	os << hex << setfill('0') << setw(16) << block.high << setw(16) << block.low << dec;
	return os;
}

