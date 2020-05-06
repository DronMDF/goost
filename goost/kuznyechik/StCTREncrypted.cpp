// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StCTREncrypted.h"
#include "BlkEncrypted.h"
#include "BlkIncremented.h"
#include "BlkRaw.h"
#include "BlkXored.h"
#include "Iterator.h"

using namespace std;
using namespace kuznyechik;

class ItCTREncrypted final : public Iterator {
public:
	ItCTREncrypted(
		const shared_ptr<const Iterator> &iter,
		const shared_ptr<const Key> &key,
		const shared_ptr<const Block> &ctr
	);

	pair<uint64_t, uint64_t> value() const override;
	bool last() const override;
	size_t size() const override;
	shared_ptr<const Iterator> next() const override;

private:
	const shared_ptr<const Iterator> iter;
	const shared_ptr<const Key> key;
	const shared_ptr<const Block> ctr;
};

ItCTREncrypted::ItCTREncrypted(
		const shared_ptr<const Iterator> &iter,
		const shared_ptr<const Key> &key,
		const shared_ptr<const Block> &ctr
	) : iter(iter), key(key), ctr(ctr)
{
}

pair<uint64_t, uint64_t> ItCTREncrypted::value() const
{
	return BlkXored(iter, make_unique<BlkEncrypted>(ctr, key)).value();
}

bool ItCTREncrypted::last() const
{
	return iter->last();
}

size_t ItCTREncrypted::size() const
{
	return iter->size();
}

shared_ptr<const Iterator> ItCTREncrypted::next() const
{
	return make_shared<ItCTREncrypted>(iter->next(), key, make_shared<BlkIncremented>(ctr));
}

StCTREncrypted::StCTREncrypted(
		const shared_ptr<const Stream> &stream,
		const shared_ptr<const Key> &key,
		const uint64_t iv)
	: stream(stream), key(key), iv(iv)
{
}

shared_ptr<const Iterator> StCTREncrypted::iter() const
{
	return make_shared<const ItCTREncrypted>(stream->iter(), key, make_unique<BlkRaw>(0, iv));
}
