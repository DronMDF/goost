#pragma once
#include <memory>

namespace magma {

class Block;
class BlockIterator;
class DataStream;
class Key;

class Imit {
public:
	Imit(const std::shared_ptr<const DataStream> &data, const std::shared_ptr<const Key> &key);

	uint32_t asUint32() const;
private:
	Block do_imit(const std::shared_ptr<const BlockIterator> &iter, const Block &block) const;

	const std::shared_ptr<const DataStream> data;
	const std::shared_ptr<const Key> key;
};

}
