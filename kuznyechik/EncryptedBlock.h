#pragma once
#include <memory>
#include "Block.h"

namespace kuznyechik {

class Key;

// @todo #87:15min Need to introduce Block abstraction
//  EncryptedBlock block should be a Block.
//  Q: If block is a abstraction - value cannot return Block by value.
class EncryptedBlock final {
public:
	EncryptedBlock(const Block &block, const std::shared_ptr<const Key> &key);

	Block value() const;

private:
	const Block block;
	const std::shared_ptr<const Key> key;
};

}
