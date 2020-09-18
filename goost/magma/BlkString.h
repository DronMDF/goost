// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include "Block.h"

namespace goost {
namespace magma {

class BlkString final : public Block {
public:
	explicit BlkString(const std::string &block);
	std::pair<uint32_t, uint32_t> value() const override;
private:
	const std::string block;
};

}  // namespace magma
}  // namespace goost
