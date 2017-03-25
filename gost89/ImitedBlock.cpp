#include "ImitedBlock.h"

using namespace std;
using namespace gost89;
using namespace magma;

ImitedBlock::ImitedBlock(const Block &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

Block ImitedBlock::value() const
{
	return key->forward(key->forward(block));
}
