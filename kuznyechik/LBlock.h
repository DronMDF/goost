// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "BlkRaw.h"

namespace kuznyechik {

// @todo #183 Rename LBlock to BlkL
// @todo #183 BlkL should take pointer to Block instead BlkRaw
class LBlock final : public Block {
public:
	explicit LBlock(const BlkRaw &block);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const BlkRaw block;
	BlkRaw transform(const BlkRaw &b, int n) const;
};

}
