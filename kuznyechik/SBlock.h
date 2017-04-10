#pragma once
#include "Block.h"

namespace kuznyechik {

class SBlock final {
public:
	explicit SBlock(const Block &block);

	Block value() const;

private:
	const Block block;
};

}
