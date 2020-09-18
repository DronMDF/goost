// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"

namespace goost {
namespace magma {

class Iterator : public Block {
public:
	virtual bool last() const = 0;
	virtual size_t size() const = 0;
	virtual std::shared_ptr<const Iterator> next() const = 0;
};

}
}  // namespace goost
