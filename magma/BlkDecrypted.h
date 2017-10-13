// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "BlkRaw.h"
#include "Block.h"

namespace magma {

class Key;

// @todo #274 magma::BlkDecrypted should take pointer to magma::Block
class BlkDecrypted final : public Block {
public:
	BlkDecrypted(const BlkRaw &block, const std::shared_ptr<const Key> &key);
	std::pair<uint32_t, uint32_t> value() const override;
private:
	const BlkRaw block;
	const std::shared_ptr<const Key> key;
};

}
