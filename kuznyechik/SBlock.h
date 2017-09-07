// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "BlkRaw.h"

namespace kuznyechik {

class SBlock final {
public:
	explicit SBlock(const BlkRaw &block);

	BlkRaw value() const;

private:
	const BlkRaw block;
};

}
