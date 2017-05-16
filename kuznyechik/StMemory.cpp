#include "StMemory.h"
#include "Block.h"
#include "Iterator.h"

using namespace std;
using namespace kuznyechik;

namespace kuznyechik {

class ItMemory final : public Iterator {
public:
	ItMemory(const weak_ptr<const StMemory> &stream_ptr,
		size_t offset, const Block &data);

	bool last() const override;
	size_t size() const override;
	Block value() const override;
	shared_ptr<const Iterator> next() const override;
private:
	const weak_ptr<const StMemory> stream_ptr;
	const size_t offset;
	const Block data;
};

}

ItMemory::ItMemory(const weak_ptr<const StMemory> &stream_ptr,
		size_t offset, const Block &data)
	: stream_ptr(stream_ptr), offset(offset), data(data)
{
}

bool ItMemory::last() const
{
	return !next();
}

size_t ItMemory::size() const
{
	return sizeof(Block);
}

Block ItMemory::value() const
{
	return data;
}

shared_ptr<const Iterator> ItMemory::next() const
{
	const auto stream = stream_ptr.lock();
	return stream->next_iter(offset + sizeof(Block));
}

StMemory::StMemory(const vector<uint64_t> &data)
	: data(data)
{
}

shared_ptr<const Iterator> StMemory::iter() const
{
	return next_iter(0);
}

shared_ptr<const Iterator> StMemory::next_iter(size_t offset) const
{
	if (data.size() <= offset / sizeof(uint64_t)) {
		return {};
	}
	return make_shared<const ItMemory>(
		shared_from_this(),
		offset,
		Block(&data[offset / sizeof(uint64_t)])
	);
}
