// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <ostream>
#include <vector>
#include "Block.h"

namespace magma {

class BlkRaw final : public Block {
public:
	BlkRaw();
	explicit BlkRaw(uint64_t block);
	explicit BlkRaw(const std::vector<uint8_t> &block);
	explicit BlkRaw(const void *ptr);
	BlkRaw(uint32_t low, uint32_t high);

	std::pair<uint32_t, uint32_t> value() const override;

	// @todo #274 Add magma::BlkShifted
	BlkRaw operator <<(int i) const;
	// @todo #274 Add magma::BlkXored
	BlkRaw operator ^(const BlkRaw &b) const;

private:
	const uint32_t low;
	const uint32_t high;
};

}
