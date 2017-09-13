// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StCTREncrypted.h"
#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "Iterator.h"

using namespace std;
using namespace kuznyechik;

// @todo #103 ItCTREncrypted should take pointer to ctr as Block, not imm BlkRaw value
class ItCTREncrypted final : public Iterator {
public:
	ItCTREncrypted(
		const shared_ptr<const Iterator> &iter,
		const shared_ptr<const Key> &key,
		const BlkRaw &ctr
	);

	bool last() const override;
	size_t size() const override;
	BlkRaw value() const override;
	shared_ptr<const Iterator> next() const override;

private:
	const shared_ptr<const Iterator> iter;
	const shared_ptr<const Key> key;
	const BlkRaw ctr;
};

ItCTREncrypted::ItCTREncrypted(
		const shared_ptr<const Iterator> &iter,
		const shared_ptr<const Key> &key,
		const BlkRaw &ctr)
	: iter(iter), key(key), ctr(ctr)
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
	BlkEncrypted block(ctr, key);
	return iter->value() ^ BlkRaw(block.value());
}

shared_ptr<const Iterator> ItCTREncrypted::next() const
{
	return make_shared<const ItCTREncrypted>(
		iter->next(),
		key,
		BlkRaw(ctr.low + 1, ctr.high)
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
	return make_shared<const ItCTREncrypted>(stream->iter(), key, BlkRaw(0, iv));
}
