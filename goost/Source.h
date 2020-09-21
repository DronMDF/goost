// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

namespace goost {

class Source {
public:
	virtual ~Source() = default;

	virtual std::pair<std::vector<std::byte>, std::shared_ptr<const Source>> read(size_t size) const = 0;
};

}  // namespace goost
