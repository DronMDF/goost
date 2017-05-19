// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <memory>
#include <vector>

namespace magma {

class BlockIterator;

// @todo #102:15min Introduce magma::Stream interface
class DataStream : public std::enable_shared_from_this<const DataStream> {
public:
	explicit DataStream(const std::vector<uint64_t> &data);

	std::shared_ptr<const BlockIterator> iter(size_t offset = 0) const;

private:
	const std::vector<uint64_t> data;
};

}
