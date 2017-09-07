// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StCTREncrypted.h"
#include "BlkRaw.h"
#include "EncryptedBlock.h"
#include "Iterator.h"

using namespace std;
using namespace kuznyechik;

// @todo #95:15min Rename CTREncryptedIterator to ItCTREncrypted
class CTREncryptedIterator final : public Iterator {
public:
	CTREncryptedIterator(
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

CTREncryptedIterator::CTREncryptedIterator(
		const shared_ptr<const Iterator> &iter,
		const shared_ptr<const Key> &key,
		const BlkRaw &ctr)
	: iter(iter), key(key), ctr(ctr)
{
}

bool CTREncryptedIterator::last() const
{
	return iter->last();
}

size_t CTREncryptedIterator::size() const
{
	return iter->size();
}

BlkRaw CTREncryptedIterator::value() const
{
	EncryptedBlock block(ctr, key);
	return iter->value() ^ BlkRaw(block.value());
}

shared_ptr<const Iterator> CTREncryptedIterator::next() const
{
	return make_shared<const CTREncryptedIterator>(
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
	return make_shared<const CTREncryptedIterator>(stream->iter(), key, BlkRaw(0, iv));
}
