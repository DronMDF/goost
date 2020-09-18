// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstddef>
#include <memory>
#include <vector>

namespace goost {

class Sink {
public:
	virtual ~Sink() = default;

	virtual std::shared_ptr<const Sink> write(const std::vector<std::byte> &data) const = 0;

	// This method return underlaying sink
	virtual std::shared_ptr<const Sink> finalize() const = 0;
};

}  // namespace goost
