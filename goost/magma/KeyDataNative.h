// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "KeyData.h"
#include <vector>

namespace goost {
namespace magma {

class KeyDataNative : public KeyData {
public:
	explicit KeyDataNative(const std::vector<uint32_t> &key_data);
	uint32_t key(int index) const final;
private:
	const std::vector<uint32_t> key_data;
};

}  // namespace magma
}  // namespace goost
