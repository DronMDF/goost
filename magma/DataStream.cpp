// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "DataStream.h"
#include "Block.h"
#include "BlockIterator.h"

using namespace std;
using namespace magma;

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
	return 8;
}

Block DataStreamIterator::value() const
{
	return data;
}

shared_ptr<const BlockIterator> DataStreamIterator::next() const
{
	const auto stream = stream_ptr.lock();
	return stream->iter(offset + 8);
}

DataStream::DataStream(const vector<uint64_t> &data)
	: data(data)
{
}

shared_ptr<const BlockIterator> DataStream::iter(size_t offset) const
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
