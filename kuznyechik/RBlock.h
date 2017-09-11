// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "BlkRaw.h"

namespace kuznyechik {

// @todo #159 Rename RBlock to BlkR
// @todo #159 BlkR should take pointer to Block, not BlkRaw
class RBlock final : public Block {
public:
	explicit RBlock(const BlkRaw &block);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const BlkRaw block;
	uint8_t gmul(uint8_t a, uint8_t b) const;
};

}
