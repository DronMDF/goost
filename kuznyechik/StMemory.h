#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "Iterator.h"
#include "Stream.h"

namespace kuznyechik {

class StMemory final :
	public Stream,
	public std::enable_shared_from_this<const StMemory>
{
public:
	explicit StMemory(const std::vector<uint64_t> &data);

	virtual std::shared_ptr<const Iterator> iter() const override;
	std::shared_ptr<const Iterator> next_iter(size_t offset = 0) const;

private:
	const std::vector<uint64_t> data;
};

}
