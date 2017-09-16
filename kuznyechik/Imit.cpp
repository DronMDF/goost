// Copyright (c) 2017 Andrey Valyaev
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
using namespace kuznyechik;

namespace kuznyechik {

// This class xor a<<1 and B if high bit of a is 1
class BlkXoredIfHighBit final : public Block {
public:
	BlkXoredIfHighBit(const shared_ptr<const Block> &a, const shared_ptr<const Block> &b)
		: a(a), b(b)
	{
	}

	pair<uint64_t, uint64_t> value() const override
	{
		const auto a_value = a->value();
		const auto a_shift = make_shared<BlkShifted>(a, 1);
		if ((a_value.second & 0x8000000000000000) == 0) {
			return a_shift->value();
		}
		return BlkXored(a_shift, b).value();
	}

private:
	const shared_ptr<const Block> a;
	const shared_ptr<const Block> b;
};

}

Imit::Imit(const shared_ptr<const Stream> &data, const shared_ptr<const Key> &key)
	: data(data), key(key)
{
}

std::pair<uint64_t, uint64_t> Imit::value() const
{
	auto iter = data->iter();
	shared_ptr<const Block> block = make_shared<const BlkRaw>();

	while (!iter->last()) {
		block = make_shared<const BlkEncrypted>(
			make_unique<BlkXored>(block, make_unique<BlkRaw>(iter->value())),
			key
		);
		iter = iter->next();
	}

	const auto B = make_shared<BlkRaw>(0x87);
	const auto K1 = make_shared<BlkXoredIfHighBit>(
		make_unique<BlkEncrypted>(make_unique<BlkRaw>(), key),
		B
	);
	const auto xblock = make_shared<BlkXored>(block, make_unique<BlkRaw>(iter->value()));

	if (iter->size() == Block::size) {
		return BlkEncrypted(make_unique<BlkXored>(xblock, K1), key).value();
	}

	return BlkEncrypted(
		make_unique<BlkXored>(xblock, make_unique<BlkXoredIfHighBit>(K1, B)),
		key
	).value();
}
