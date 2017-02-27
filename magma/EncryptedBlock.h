#pragma once
#include <memory>
#include "Block.h"

namespace magma {

class Key;

class EncryptedBlock {
public:
	EncryptedBlock(const Block &block, const std::shared_ptr<const Key> &key);

	Block value() const;

private:
	const Block block;
	const std::shared_ptr<const Key> key;
};

}
