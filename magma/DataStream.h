// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "Stream.h"

namespace magma {

// @todo #108 Rename magma::DataStream to magma::StMemory
class DataStream final : public Stream, public std::enable_shared_from_this<const DataStream> {
public:
	explicit DataStream(const std::vector<uint64_t> &data);
	std::shared_ptr<const Iterator> iter() const override;
	std::shared_ptr<const Iterator> next_iter(size_t offset = 0) const;
private:
	const std::vector<uint64_t> data;
};

}
