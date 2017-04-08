#include "EncryptedBlock.h"
#include "Key.h"

using namespace std;
using namespace kuznyechik;

EncryptedBlock::EncryptedBlock(const Block &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

Block EncryptedBlock::value() const
{
	return key->encrypt(block);
}

