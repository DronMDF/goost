#include "Imit.h"
#include "Block.h"
#include "BlockIterator.h"
#include "DataStream.h"
#include "EncryptedBlock.h"
#include "ImitedBlock.h"
#include <iostream>

using namespace std;
using namespace magma;

Imit::Imit(const shared_ptr<const DataStream> &data, const shared_ptr<const Key> &key)
	: data(data), key(key)
{
}

uint32_t Imit::asUint32() const
{
	return do_imit(data->iter(), Block()).high;
}

Block Imit::do_imit(const shared_ptr<const BlockIterator> &iter, const Block &block) const
{
	if (iter->last()) {
		const auto R = EncryptedBlock({}, key).value();
		const Block B{0x1b};
		const auto K1 = ((R.high & 0x80000000) == 0) ? (R << 1) : (R << 1) ^ B;
		if (iter->size() == 8) {
			return EncryptedBlock(block ^ iter->value() ^ K1, key).value();
		}

		const auto K2 = ((K1.high & 0x80000000) == 0) ? (K1 << 1) : (K1 << 1) ^ B;
		return EncryptedBlock(block ^ iter->value() ^ K2, key).value();
	}

	return do_imit(iter->next(), EncryptedBlock(block ^ iter->value(), key).value());
}
