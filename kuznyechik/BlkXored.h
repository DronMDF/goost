// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace kuznyechik {

// @todo #219 BlkXored ctor taked many args
class BlkXored final : public Block {
public:
	BlkXored(const std::shared_ptr<const Block> &a, const std::shared_ptr<const Block> &b);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Block> a;
	const std::shared_ptr<const Block> b;
};

}
