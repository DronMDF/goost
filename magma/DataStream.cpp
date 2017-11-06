// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "DataStream.h"
#include "BlkRaw.h"
#include "Iterator.h"

using namespace std;
using namespace magma;

class DataStreamIterator final : public Iterator {
public:
	DataStreamIterator(const weak_ptr<const DataStream> &stream_ptr,
		size_t offset, const BlkRaw &data);

	std::pair<uint32_t, uint32_t> value() const override;

	bool last() const override;
	size_t size() const override;
	shared_ptr<const Iterator> next() const override;
private:
	const weak_ptr<const DataStream> stream_ptr;
	const size_t offset;
	const BlkRaw data;
};

DataStreamIterator::DataStreamIterator(const weak_ptr<const DataStream> &stream_ptr,
		size_t offset, const BlkRaw &data)
	: stream_ptr(stream_ptr), offset(offset), data(data)
{
}

pair<uint32_t, uint32_t> DataStreamIterator::value() const
{
	return data.value();
}

bool DataStreamIterator::last() const
{
	return !next();
}

size_t DataStreamIterator::size() const
{
	return 8;
}

shared_ptr<const Iterator> DataStreamIterator::next() const
{
	const auto stream = stream_ptr.lock();
	return stream->next_iter(offset + 8);
}

DataStream::DataStream(const vector<uint64_t> &data)
	: data(data)
{
}

shared_ptr<const Iterator> DataStream::iter() const
{
	return next_iter(0);
}

shared_ptr<const Iterator> DataStream::next_iter(size_t offset) const
{
	if (data.size() <= offset / sizeof(uint64_t)) {
		return {};
	}
	return make_shared<const DataStreamIterator>(
		shared_from_this(),
		offset,
		BlkRaw(&data[offset / sizeof(uint64_t)])
	);
}
