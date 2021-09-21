// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include <goost/magma/Container.h>

namespace goost {
namespace magma {

// This class provide unified access for variadic key containers
// like file, hexdump, etc...
class HexContainer final : public Container {
public:
	explicit HexContainer(const std::string &hex);
	std::vector<std::byte> key() const override;
	std::vector<std::byte> mask() const override;
	std::vector<std::byte> sbox() const override;
private:
	const std::string hex;
};

}
}
