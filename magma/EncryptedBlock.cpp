#include "EncryptedBlock.h"
#include "Key.h"

using namespace std;
using namespace magma;

EncryptedBlock::EncryptedBlock(const Block &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

Block EncryptedBlock::value() const
{
	const auto rb = key->backward(key->forward(key->forward(key->forward(block))));
	return Block(rb.high, rb.low);
}
