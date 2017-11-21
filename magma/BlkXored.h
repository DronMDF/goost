// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace magma {

class BlkXored final : public Block {
public:
	BlkXored(const std::shared_ptr<const Block> &a, const std::shared_ptr<const Block> &b);

	template <typename ...B>
	BlkXored(
		const std::shared_ptr<const Block> &a,
		const std::shared_ptr<const Block> &b,
		const std::shared_ptr<const Block> &c,
		const B &...d
	) : BlkXored(std::make_unique<BlkXored>(a, b), c, d...)
	{
	}

	std::pair<uint32_t, uint32_t> value() const override;
private:
	const std::shared_ptr<const Block> a;
	const std::shared_ptr<const Block> b;
};

}  // namespace magma
