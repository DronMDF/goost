// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"

namespace kuznyechik {

class SBlock final {
public:
	explicit SBlock(const Block &block);

	Block value() const;

private:
	const Block block;
};

}
