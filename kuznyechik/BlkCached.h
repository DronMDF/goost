// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace kuznyechik {

class BlkCached final : public Block {
public:
	explicit BlkCached(const std::shared_ptr<const Block> &block);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	class BlockCache;
	// non-const cache
	const std::shared_ptr<BlockCache> cache;
};

}
