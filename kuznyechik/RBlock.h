// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "BlkRaw.h"

namespace kuznyechik {

// @todo #59 Need to introduce abstract interface for Block.
//  For the sake of speed, I want BlkRaw to be a non-polymorphic type,
//  but premature optimization is evil, and maybe it's worth making
//  it polymorphic, then RBlock, EnkriptedBlock will implement its
//  interface.
class RBlock final {
public:
	explicit RBlock(const BlkRaw &block);

	BlkRaw value() const;

private:
	const BlkRaw block;

	uint8_t gmul(uint8_t a, uint8_t b) const;
};

}
