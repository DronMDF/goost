// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace goost {
namespace magma {

class Key;

class BlkDecrypted final : public Block {
public:
	BlkDecrypted(
		const std::shared_ptr<const Block> &block,
		const std::shared_ptr<const Key> &key
	);
	std::pair<uint32_t, uint32_t> value() const override;
private:
	const std::shared_ptr<const Block> block;
};

}  // namespace magma
}  // namespace goost
