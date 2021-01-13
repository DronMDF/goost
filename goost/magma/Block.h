// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <utility>

namespace goost {
namespace magma {

class Block {
public:
	virtual ~Block() = default;
	virtual std::pair<uint32_t, uint32_t> value() const = 0;

	static constexpr auto size = sizeof(uint32_t) * 2;
};

}  // namespace magma
}  // namespace goost
