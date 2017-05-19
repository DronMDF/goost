// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace kuznyechik {

class Block;

// This is abstract Iterator type
// Prefix for implementations is It
class Iterator {
public:
	virtual ~Iterator() = default;

	virtual bool last() const = 0;
	virtual size_t size() const = 0;
	virtual Block value() const = 0;
	virtual std::shared_ptr<const Iterator> next() const = 0;
};

}
