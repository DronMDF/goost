#include "Block.h"

using namespace magma;

Block::Block(uint32_t low, uint32_t high)
	: low(low), high(high)
{
}

Block::Block(const void *ptr)
	: low(reinterpret_cast<const uint32_t *>(ptr)[0]),
	  high(reinterpret_cast<const uint32_t *>(ptr)[1])
{
}
