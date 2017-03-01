#include "Block.h"
#include <iomanip>

using namespace std;
using namespace magma;

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

ostream &magma::operator <<(ostream &os, const Block &block)
{
	os << hex << setw(8) << setfill('0') << block.high << block.low;
	return os;
}
