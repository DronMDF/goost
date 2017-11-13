// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace magma {

class BlkSwapped final : public Block {
public:
	explicit BlkSwapped(const std::shared_ptr<const Block> &block);
	std::pair<uint32_t, uint32_t> value() const override;
private:
	const std::shared_ptr<const Block> block;
};

}