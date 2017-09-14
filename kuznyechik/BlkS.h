// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "BlkRaw.h"

namespace kuznyechik {

// @todo #160 BlkS should take pointer to Block, not BlkRaw
class BlkS final : public Block {
public:
	explicit BlkS(const BlkRaw &block);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const BlkRaw block;
};

}
