#include "Block.h"
#include <iomanip>

using namespace std;
using namespace magma;

Block::Block()
	: Block(0LU)
{
}

Block::Block(uint64_t low)
	: Block(low, low >> 32)
{
}

Block::Block(const vector<uint8_t> &block)
	: Block(
		reinterpret_cast<const uint32_t *>(&block[0])[0],
		reinterpret_cast<const uint32_t *>(&block[0])[1]
	  )
{
}

Block::Block(const void *ptr)
	: Block(
		reinterpret_cast<const uint32_t *>(ptr)[0],
		reinterpret_cast<const uint32_t *>(ptr)[1]
	  )
{
}

Block::Block(uint32_t low, uint32_t high)
	: low(low), high(high)
{
}

bool Block::operator ==(const Block &block) const
{
	return low == block.low && high == block.high;
}

Block Block::operator <<(int i) const
{
	return {low << i, high << i | low >> (32 - i)};
}

Block Block::operator ^(const Block &b) const
{
	return {low ^ b.low, high ^ b.high};
}

ostream &magma::operator <<(ostream &os, const Block &block)
{
	os << hex << setfill('0') << setw(8) << block.high << setw(8) << block.low << dec;
	return os;
}
