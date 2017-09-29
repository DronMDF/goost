// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include "Block.h"

namespace kuznyechik {

class BlkString final : public Block {
public:
	explicit BlkString(const std::string &block);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::string block;
};

}
