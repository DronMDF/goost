// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace goost {
namespace magma {

class Key {
public:
	virtual ~Key() = default;
	virtual uint32_t transform(uint32_t v, int index) const = 0;
};

}
}
