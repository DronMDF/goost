// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <ostream>

namespace kuznyechik {

// @todo #170 BlkRaw should have Block type
class BlkRaw {
public:
	BlkRaw(uint64_t low, uint64_t high);
	explicit BlkRaw(const std::pair<uint64_t, uint64_t> &value);
	explicit BlkRaw(const void * const ptr);
	explicit BlkRaw(uint64_t low);
	BlkRaw();

	bool operator ==(const BlkRaw &block) const;
	BlkRaw operator <<(int i) const;
	BlkRaw operator ^(const BlkRaw &b) const;

	const uint64_t low;
	const uint64_t high;
};

std::ostream &operator <<(std::ostream &os, const BlkRaw &block);

}
