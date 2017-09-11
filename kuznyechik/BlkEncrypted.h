// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "BlkRaw.h"
#include "Block.h"

namespace kuznyechik {

class Key;

// @todo #189 BlkEncrypted Ctor take pointer to Block, not imm BlkRaw
class BlkEncrypted final : public Block {
public:
	BlkEncrypted(const BlkRaw &block, const std::shared_ptr<const Key> &key);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const BlkRaw block;
	const std::shared_ptr<const Key> key;
};

}
