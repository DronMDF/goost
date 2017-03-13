#pragma once

namespace magma {

class Block;

class BlockIterator {
public:
	virtual ~BlockIterator() = default;

	virtual bool last() const = 0;
	virtual size_t size() const = 0;
	virtual Block value() const = 0;
	virtual std::shared_ptr<const BlockIterator> next() const = 0;
};

}
