#pragma once

namespace kuznyechik {

class Block;

// @todo #59:30min Remove Operations, this is a utility class
// Need to introduce Small classes for transformed blocks
class Operations {
public:
	Block S(const Block &a) const;
	Block L(const Block &a) const;
};

}
