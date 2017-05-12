#pragma once
#include <memory>

namespace kuznyechik {

class Iterator;

// This is abstract stream type.
// Prefix for classes is 'St'
class Stream {
public:
	virtual ~Stream() = default;

	virtual std::shared_ptr<const Iterator> iter() const = 0;
};

}
