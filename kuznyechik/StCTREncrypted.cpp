// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StCTREncrypted.h"
#include "BlkEncrypted.h"
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

	bool last() const override;
	size_t size() const override;
	BlkRaw value() const override;
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

bool ItCTREncrypted::last() const
{
	return iter->last();
}

size_t ItCTREncrypted::size() const
{
	return iter->size();
}

BlkRaw ItCTREncrypted::value() const
{
	return BlkRaw(
		make_unique<BlkXored>(
			make_unique<BlkRaw>(iter->value()),
			make_unique<BlkEncrypted>(ctr, key)
		)
	);
}

shared_ptr<const Iterator> ItCTREncrypted::next() const
{
	// @todo #233 Add BlkIncremented (Block, Increased by n) instead imp value increment
	const auto value = ctr->value();
	return make_shared<const ItCTREncrypted>(
		iter->next(),
		key,
		make_unique<BlkRaw>(value.first + 1, value.second)
	);
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
