// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"

namespace kuznyechik {

class LBlock final {
public:
	explicit LBlock(const Block &block);

	Block value() const;

private:
	const Block block;

	Block transform(const Block &b, int n) const;
};

}
