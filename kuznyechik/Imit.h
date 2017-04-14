#pragma once
#include <memory>

namespace kuznyechik {

class Block;
class DataStream;
class Key;

class Imit {
public:
	Imit(const std::shared_ptr<const DataStream> &data, const std::shared_ptr<const Key> &key);

	Block value() const;
private:
	const std::shared_ptr<const DataStream> data;
	const std::shared_ptr<const Key> key;
};

}

