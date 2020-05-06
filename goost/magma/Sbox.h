// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>

namespace magma {

class Sbox {
public:
	virtual ~Sbox() = default;
	virtual uint32_t transform(uint32_t value) const = 0;
};

}
