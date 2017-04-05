#pragma once
#include <cstdint>
#include <ostream>

namespace kuznyechik {

class Block {
public:
	Block(uint64_t low, uint64_t high);

	bool operator ==(const Block &block) const;

	const uint64_t low;
	const uint64_t high;
};

std::ostream &operator <<(std::ostream &os, const Block &block);

}
