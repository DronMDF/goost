#include "DataStream.h"
#include "Block.h"
#include "BlockIterator.h"

using namespace std;
using namespace kuznyechik;

namespace kuznyechik {

class DataStreamIterator final : public BlockIterator {
public:
	DataStreamIterator(const weak_ptr<const DataStream> &stream_ptr,
		size_t offset, const Block &data);

	bool last() const override;
	size_t size() const override;
	Block value() const override;
	shared_ptr<const BlockIterator> next() const override;
private:
	const weak_ptr<const DataStream> stream_ptr;
	const size_t offset;
	const Block data;
};

}

DataStreamIterator::DataStreamIterator(const weak_ptr<const DataStream> &stream_ptr,
		size_t offset, const Block &data)
	: stream_ptr(stream_ptr), offset(offset), data(data)
{
}

bool DataStreamIterator::last() const
{
	return !next();
}

size_t DataStreamIterator::size() const
{
	return sizeof(Block);
}

Block DataStreamIterator::value() const
{
	return data;
}

shared_ptr<const BlockIterator> DataStreamIterator::next() const
{
	const auto stream = stream_ptr.lock();
	return stream->next_iter(offset + sizeof(Block));
}

DataStream::DataStream(const vector<uint64_t> &data)
	: data(data)
{
}

shared_ptr<const BlockIterator> DataStream::iter() const
{
	return next_iter(0);
}

shared_ptr<const BlockIterator> DataStream::next_iter(size_t offset) const
{
	if (data.size() <= offset / sizeof(uint64_t)) {
		return {};
	}
	return make_shared<const DataStreamIterator>(
		shared_from_this(),
		offset,
		Block(&data[offset / sizeof(uint64_t)])
	);
}
