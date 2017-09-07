// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Key.h"
#include <string>

namespace kuznyechik {

class KeyDataString final : public Key::Data {
public:
	explicit KeyDataString(const std::string &key_data);
	BlkRaw low() const override;
	BlkRaw high() const override;
private:
	const std::string key_data;
};

}

