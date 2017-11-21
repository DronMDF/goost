// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace kuznyechik {

class BlkIterKey final : public Block {
public:
	BlkIterKey(
		const std::shared_ptr<const Block> &ka,
		const std::shared_ptr<const Block> &kb,
		int c1, int c2
	);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Block> ka;
	const std::shared_ptr<const Block> kb;
	const int c1;
	const int c2;

	std::shared_ptr<const Block> generate(
		const std::shared_ptr<const Block> &a,
		const std::shared_ptr<const Block> &b,
		int i
	) const;
};

}  // namespace kuznyechik
