// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstddef>
#include <vector>

namespace goost {
namespace magma {

// This class provide unified access for variadic key containers
// like file, hexdump, etc...
class Container {
public:
	virtual ~Container() = default;
	// 32 bytes key
	virtual std::vector<std::byte> key() const = 0;
	// 32 bytes mask
	virtual std::vector<std::byte> mask() const = 0;
	// 64 bytes sbox
	virtual std::vector<std::byte> sbox() const = 0;
};

}
}
