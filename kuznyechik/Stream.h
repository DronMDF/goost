#pragma once
#include <memory>

namespace kuznyechik {

// @todo #93:15min Rename BlockIterator to Iterator, KISS
class BlockIterator;

// This is abstract stream type.
// Prefix for classes is 'St'
class Stream {
public:
	virtual ~Stream() = default;

	virtual std::shared_ptr<const BlockIterator> iter() const = 0;
};

}
