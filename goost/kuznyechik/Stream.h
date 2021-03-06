// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace goost {
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
}  // namespace goost
