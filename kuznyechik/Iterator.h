// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"

namespace kuznyechik {

// This is abstract Iterator type
// Prefix for implementations is It
class Iterator : public Block {
public:
	std::pair<uint64_t, uint64_t> value() const override = 0;

	virtual bool last() const = 0;
	virtual size_t size() const = 0;
	virtual std::shared_ptr<const Iterator> next() const = 0;
};

}  // namespace kuznyechik
