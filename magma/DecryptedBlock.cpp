#include "DecryptedBlock.h"
#include "Key.h"

using namespace std;
using namespace magma;

DecryptedBlock::DecryptedBlock(const Block &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

Block DecryptedBlock::value() const
{
	const auto rb = key->backward(key->backward(key->backward(key->forward(block))));
	return {rb.high, rb.low};
}
