// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

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

}  // namespace kuznyechik
