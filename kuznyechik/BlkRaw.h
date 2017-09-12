// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include "Block.h"

namespace kuznyechik {

class BlkRaw final : public Block {
public:
	BlkRaw(uint64_t low, uint64_t high);
	explicit BlkRaw(const std::pair<uint64_t, uint64_t> &value);
	explicit BlkRaw(const std::shared_ptr<const Block> &block);
	explicit BlkRaw(const void * const ptr);
	explicit BlkRaw(uint64_t low);
	BlkRaw();

	bool operator ==(const BlkRaw &block) const;
	BlkRaw operator <<(int i) const;
	BlkRaw operator ^(const BlkRaw &b) const;

	std::pair<uint64_t, uint64_t> value() const override;

	const uint64_t low;
	const uint64_t high;
};

std::ostream &operator <<(std::ostream &os, const BlkRaw &block);

}
