// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>

namespace kuznyechik {

// @todo #170 Introduce BlkShifted, whoes value is left shofted by n bit
// @todo #170 Introduce BlkXored, whoes value is xor of two block

class Block {
public:
	virtual ~Block() = default;
	virtual std::pair<uint64_t, uint64_t> value() const = 0;
};

}
