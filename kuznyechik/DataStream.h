#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "BlockIterator.h"
#include "Stream.h"

namespace kuznyechik {

// @todo #93:15min Reame DataStream to StMemory, DataStream is very abstract name.
class DataStream final :
	public Stream,
	public std::enable_shared_from_this<const DataStream>
{
public:
	explicit DataStream(const std::vector<uint64_t> &data);

	virtual std::shared_ptr<const BlockIterator> iter() const override;
	std::shared_ptr<const BlockIterator> next_iter(size_t offset = 0) const;

private:
	const std::vector<uint64_t> data;
};

}
