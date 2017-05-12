#pragma once
#include <memory>

namespace kuznyechik {

class Block;
class Key;
class Stream;

class Imit {
public:
	Imit(const std::shared_ptr<const Stream> &data, const std::shared_ptr<const Key> &key);

	Block value() const;
private:
	const std::shared_ptr<const Stream> data;
	const std::shared_ptr<const Key> key;
};

}

