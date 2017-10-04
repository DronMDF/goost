// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <ostream>
#include <vector>

namespace magma {

class BlkRaw {
public:
	BlkRaw();
	explicit BlkRaw(uint64_t block);
	explicit BlkRaw(const std::vector<uint8_t> &block);
	explicit BlkRaw(const void *ptr);
	BlkRaw(uint32_t low, uint32_t high);

	bool operator ==(const BlkRaw &block) const;
	// @todo #274 Add magma::BlkShifted
	BlkRaw operator <<(int i) const;
	// @todo #274 Add magma::BlkXored
	BlkRaw operator ^(const BlkRaw &b) const;

	const uint32_t low;
	const uint32_t high;
};

// @todo #274 Add magma::ReprBlock instead operator <<
std::ostream &operator <<(std::ostream &os, const BlkRaw &block);

}
