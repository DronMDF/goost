// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace kuznyechik {

class Key;

class BlkEncrypted final : public Block {
public:
	BlkEncrypted(
		const std::shared_ptr<const Block> &block,
		const std::shared_ptr<const Key> &key
	);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Block> block;
	const std::shared_ptr<const Key> key;
};

}  // namespace kuznyechik
