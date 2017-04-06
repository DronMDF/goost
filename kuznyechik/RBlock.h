#pragma once
#include "Block.h"

namespace kuznyechik {

class RBlock final {
public:
	explicit RBlock(const Block &block);

	Block value() const;

private:
	const Block block;
};

}
