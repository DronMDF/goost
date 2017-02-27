#pragma once
#include <cstdint>
#include <ostream>
#include <vector>

namespace magma {

class Block {
public:
	explicit Block(const std::vector<uint8_t> &block);
	explicit Block(const void *ptr);
	Block(uint32_t low, uint32_t high);

	bool operator ==(const Block &block) const;

	const uint32_t low;
	const uint32_t high;
};

std::ostream &operator <<(std::ostream &os, const Block &block);

}
