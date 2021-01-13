// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>

namespace goost {
namespace magma {

class KeyData {
public:
	virtual ~KeyData() = default;
	virtual uint32_t key(int index) const = 0;
};

}  // namespace magma
}  // namespace goost
