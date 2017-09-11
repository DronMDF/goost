// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "BlkRaw.h"

namespace kuznyechik {

// @todo #160 Rename Sblock to BlkS
// @todo #160 BlkS should take pointer to Block, not BlkRaw
class SBlock final : public Block {
public:
	explicit SBlock(const BlkRaw &block);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const BlkRaw block;
};

}
