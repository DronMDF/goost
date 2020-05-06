// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>

namespace magma {

class KeyData {
public:
	virtual ~KeyData() = default;
	virtual uint32_t key(int index) const = 0;
};

}  // namespace magma
