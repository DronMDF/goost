#pragma once
#include <memory>

namespace magma {

class Block;
class BlockIterator;
class DataStream;
class Key;

class Imit final {
public:
	Imit(const std::shared_ptr<const DataStream> &data, const std::shared_ptr<const Key> &key);

	Block value() const;
private:
	const std::shared_ptr<const DataStream> data;
	const std::shared_ptr<const Key> key;
};

}