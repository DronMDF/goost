#pragma once
#include <cstdint>
#include <ostream>

namespace kuznyechik {

class Block {
public:
	Block();
	explicit Block(uint64_t low);
	explicit Block(const void * const ptr);
	Block(uint64_t low, uint64_t high);

	bool operator ==(const Block &block) const;
	Block operator ^(const Block &b) const;

	const uint64_t low;
	const uint64_t high;
};

std::ostream &operator <<(std::ostream &os, const Block &block);

}
