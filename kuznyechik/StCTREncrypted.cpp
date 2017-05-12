#include "StCTREncrypted.h"
#include "Block.h"
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
		const Block &ctr
	);

	bool last() const override;
	size_t size() const override;
	Block value() const override;
	shared_ptr<const Iterator> next() const override;

private:
	const shared_ptr<const Iterator> iter;
	const shared_ptr<const Key> key;
	const Block ctr;
};

CTREncryptedIterator::CTREncryptedIterator(
		const shared_ptr<const Iterator> &iter,
		const shared_ptr<const Key> &key,
		const Block &ctr)
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

Block CTREncryptedIterator::value() const
{
	EncryptedBlock block(ctr, key);
	return iter->value() ^ block.value();
}

shared_ptr<const Iterator> CTREncryptedIterator::next() const
{
	return make_shared<const CTREncryptedIterator>(
		iter->next(),
		key,
		Block(ctr.low + 1, ctr.high)
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
	return make_shared<const CTREncryptedIterator>(stream->iter(), key, Block(0, iv));
}
