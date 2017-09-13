// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace kuznyechik {

class BlkRaw;

// @todo #103 Iterator::value() should return pointer to Block

// This is abstract Iterator type
// Prefix for implementations is It
class Iterator {
public:
	virtual ~Iterator() = default;

	virtual bool last() const = 0;
	virtual size_t size() const = 0;
	virtual BlkRaw value() const = 0;
	virtual std::shared_ptr<const Iterator> next() const = 0;
};

}
