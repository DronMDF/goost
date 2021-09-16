// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Imit.h"
#include <cstring>
#include <goost/Source.h>
#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "BlkShifted.h"
#include "BlkXored.h"
#include "Iterator.h"

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
	BlkImitFinalKey(const shared_ptr<const LazyKey> &key, const size_t block_size);
	pair<uint32_t, uint32_t> value() const override;
private:
	const shared_ptr<const LazyKey> key;
	const size_t block_size;
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
	const shared_ptr<const LazyKey> &key,
	size_t block_size
) : key(key), block_size(block_size)
{
}

pair<uint32_t, uint32_t> BlkImitFinalKey::value() const
{
	const auto K1 = make_shared<BlkImitShifted>(
		make_shared<BlkEncrypted>(make_shared<BlkRaw>(), key)
	);
	if (block_size == 8) {
		return K1->value();
	}
	return BlkImitShifted(K1).value();
}


Imit::Imit(const shared_ptr<const Source> &data, const shared_ptr<const LazyKey> &key)
	: data(data), key(key)
{
}

pair<uint32_t, uint32_t> Imit::value() const
{
	shared_ptr<const Block> k;
	shared_ptr<const Block> block = make_shared<const BlkRaw>();
	auto s = data;

	vector<byte> b;
	tie(b, s) = s->read(Block::size);
	while (true) {
		k = make_shared<BlkImitFinalKey>(key, b.size());
		uint64_t v = 0;
		memcpy(&v, &b[0], b.size());
		block = make_shared<BlkXored>(block, make_shared<BlkRaw>(v));
		if (b.size() < Block::size) {
			break;
		}
		tie(b, s) = s->read(Block::size);
		if (b.empty()) {
			break;
		}
		block = make_shared<BlkEncrypted>(block, key);
	}

	return BlkEncrypted(make_shared<BlkXored>(block, k), key).value();
}
