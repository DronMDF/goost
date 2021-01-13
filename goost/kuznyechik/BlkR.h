// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace goost {
namespace kuznyechik {

class BlkR final : public Block {
public:
	explicit BlkR(const std::shared_ptr<const Block> &block);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Block> block;
	uint8_t gmul(uint8_t a, uint8_t b) const;
};

}  // namespace kuznyechik
}  // namespace goost
