#pragma once
#include <cstdint>

namespace magma {

class Block {
public:
	Block(uint32_t low, uint32_t high);
	explicit Block(const void *ptr);

	const uint32_t low;
	const uint32_t high;
};

}
