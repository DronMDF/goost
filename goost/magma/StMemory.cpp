// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StMemory.h"
#include "BlkRaw.h"
#include "Iterator.h"

using namespace std;
using namespace goost::magma;

namespace goost {
namespace magma {

class ItMemory final : public Iterator {
public:
	ItMemory(const weak_ptr<const StMemory> &stream_ptr,
		size_t offset, const BlkRaw &data);

	std::pair<uint32_t, uint32_t> value() const override;

	bool last() const override;
	size_t size() const override;
	shared_ptr<const Iterator> next() const override;
private:
	const weak_ptr<const StMemory> stream_ptr;
	const size_t offset;
	const BlkRaw data;
};

}  // namespace magma
}  // namespace goost

// @todo #332 Add size parameter to iterator, and he can determine last() and size() for youself.
ItMemory::ItMemory(const weak_ptr<const StMemory> &stream_ptr,
		size_t offset, const BlkRaw &data)
	: stream_ptr(stream_ptr), offset(offset), data(data)
{
}

pair<uint32_t, uint32_t> ItMemory::value() const
{
	return data.value();
}

bool ItMemory::last() const
{
	return !next();
}

size_t ItMemory::size() const
{
	return 8;
}

shared_ptr<const Iterator> ItMemory::next() const
{
	const auto stream = stream_ptr.lock();
	return stream->next_iter(offset + 8);
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
		BlkRaw(&data[offset / sizeof(uint64_t)])
	);
}
