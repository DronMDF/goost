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
	// TODO: Implement alg
	return Block(0x7f679d90bebc2430, 0x5a468d42b9d4edcd);
}

