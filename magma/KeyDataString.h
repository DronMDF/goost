// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "KeyData.h"
#include <string>

namespace magma {

class KeyDataString : public KeyData {
public:
	explicit KeyDataString(const std::string &key_data);
	uint32_t key(int index) const final;
private:
	const std::string key_data;
};

}  // namespace magma
