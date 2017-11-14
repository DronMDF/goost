// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace magma {

class Key;

// @todo #328 magma::BlkForwarded should use KeyData, not Key
//  Key is not need. and should be removed after move forward impl
//  into magma::BlkForwarded::value()

/// This is a block, transformed over key in forward direction
class BlkForwarded final : public Block {
public:
	BlkForwarded(
		const std::shared_ptr<const Block> &block,
		const std::shared_ptr<const Key> &key
	);
	std::pair<uint32_t, uint32_t> value() const override;
private:
	const std::shared_ptr<const Block> block;
	const std::shared_ptr<const Key> key;
};

}
