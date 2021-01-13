// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <memory>
#include "Block.h"

namespace goost {
namespace kuznyechik {

class BlkRaw final : public Block {
public:
	BlkRaw(uint64_t low, uint64_t high);
	explicit BlkRaw(const std::pair<uint64_t, uint64_t> &value);
	explicit BlkRaw(const std::shared_ptr<const Block> &block);
	explicit BlkRaw(const void * const ptr);
	explicit BlkRaw(uint64_t low);
	BlkRaw();

	std::pair<uint64_t, uint64_t> value() const override;
private:
	const uint64_t low;
	const uint64_t high;
};

}  // namespace kuznyechik
}  // namespace goost
