#include "LBlock.h"
#include "RBlock.h"

using namespace std;
using namespace kuznyechik;

LBlock::LBlock(const Block &block)
	: block(block)
{
}

Block LBlock::value() const
{
	return transform(block, 16);
}

Block LBlock::transform(const Block &b, int n) const
{
	if (n == 0) {
		return b;
	}

	return transform(RBlock(b).value(), n - 1);
}
