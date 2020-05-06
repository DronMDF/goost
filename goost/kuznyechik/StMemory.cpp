// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StMemory.h"
#include "BlkRaw.h"
#include "Iterator.h"

using namespace std;
using namespace kuznyechik;

namespace kuznyechik {

class ItMemory final : public Iterator {
public:
	ItMemory(
		const weak_ptr<const StMemory> &stream,
		size_t offset,
		const shared_ptr<const Block> &data
	);

	pair<uint64_t, uint64_t> value() const override;
	bool last() const override;
	size_t size() const override;
	shared_ptr<const Iterator> next() const override;
private:
	const weak_ptr<const StMemory> stream;
	const size_t offset;
	const shared_ptr<const Block> data;
};

}  // namespace kuznyechik

ItMemory::ItMemory(
	const weak_ptr<const StMemory> &stream,
	size_t offset,
	const shared_ptr<const Block> &data
) : stream(stream), offset(offset), data(data)
{
}

pair<uint64_t, uint64_t> ItMemory::value() const
{
	return data->value();
}

bool ItMemory::last() const
{
	return !next();
}

size_t ItMemory::size() const
{
	return Block::size;
}

shared_ptr<const Iterator> ItMemory::next() const
{
	const auto stream_ptr = stream.lock();
	return stream_ptr->next_iter(offset + Block::size);
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
		make_shared<BlkRaw>(&data[offset / sizeof(uint64_t)])
	);
}
