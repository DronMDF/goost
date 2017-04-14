#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "BlockIterator.h"

namespace kuznyechik {

class DataStream final : public std::enable_shared_from_this<const DataStream> {
public:
	explicit DataStream(const std::vector<uint64_t> &data);

	std::shared_ptr<const BlockIterator> iter(size_t offset = 0) const;

private:
	const std::vector<uint64_t> data;
};

}
