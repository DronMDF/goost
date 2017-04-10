#pragma once
#include "Block.h"

namespace kuznyechik {

class LBlock final {
public:
	explicit LBlock(const Block &block);

	Block value() const;

private:
	const Block block;

	Block transform(const Block &b, int n) const;
};

}
