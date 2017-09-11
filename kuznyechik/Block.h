// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>

namespace kuznyechik {

class Block {
public:
	virtual ~Block() = default;
	virtual std::pair<uint64_t, uint64_t> value() const = 0;

	static constexpr auto size = sizeof(uint64_t) * 2;
};

}
