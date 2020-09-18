// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Imit.h"
#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "BlkShifted.h"
#include "BlkXored.h"
#include "Iterator.h"
#include "Stream.h"

using namespace std;
using namespace goost::magma;

namespace goost {
namespace magma {

class BlkImitShifted final : public Block {
public:
	explicit BlkImitShifted(const shared_ptr<const Block> &block);
	pair<uint32_t, uint32_t> value() const override;
private:
	const shared_ptr<const Block> block;
};

class BlkImitFinalKey final : public Block {
public:
	BlkImitFinalKey(const shared_ptr<const Key> &key, const shared_ptr<const Iterator> &iter);
	pair<uint32_t, uint32_t> value() const override;
private:
	const shared_ptr<const Key> key;
	const shared_ptr<const Iterator> iter;
};

}  // namespace magma
}  // namespace goost

BlkImitShifted::BlkImitShifted(const shared_ptr<const Block> &block)
	: block(block)
{
}

pair<uint32_t, uint32_t> BlkImitShifted::value() const
{
	const auto b = make_shared<BlkShifted>(block, 1);
	if ((block->value().second & 0x80000000) == 0) {
		return b->value();
	}
	return BlkXored(b, make_shared<BlkRaw>(0x1b)).value();
}

BlkImitFinalKey::BlkImitFinalKey(
	const shared_ptr<const Key> &key,
	const shared_ptr<const Iterator> &iter
)
	: key(key), iter(iter)
{
}

pair<uint32_t, uint32_t> BlkImitFinalKey::value() const
{
	const auto K1 = make_shared<BlkImitShifted>(
		make_shared<BlkEncrypted>(make_shared<BlkRaw>(), key)
	);
	if (iter->size() == 8) {
		return K1->value();
	}
	return BlkImitShifted(K1).value();
}


Imit::Imit(const shared_ptr<const Stream> &data, const shared_ptr<const Key> &key)
	: data(data), key(key)
{
}

pair<uint32_t, uint32_t> Imit::value() const
{
	auto iter = data->iter();
	auto block = make_shared<const BlkRaw>();

	while (!iter->last()) {
		const auto bv = BlkEncrypted(make_shared<BlkXored>(block, iter), key).value();
		block = make_shared<BlkRaw>(bv);
		iter = iter->next();
	}

	return BlkEncrypted(
		make_shared<BlkXored>(block, iter, make_shared<BlkImitFinalKey>(key, iter)), key
	).value();
}
