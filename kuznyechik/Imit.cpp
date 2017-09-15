// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Imit.h"
#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "BlkXored.h"
#include "Iterator.h"
#include "Stream.h"

using namespace std;
using namespace kuznyechik;

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

	// @todo #219 Introduce bit operation Block object and replace imm alg to composition
	const auto R = BlkRaw(BlkEncrypted(make_unique<BlkRaw>(), key).value());
	const BlkRaw B(0x87);
	const auto K1 = ((R.high & 0x8000000000000000) == 0) ? (R << 1) : (R << 1) ^ B;
	if (iter->size() == Block::size) {
		return BlkEncrypted(
			make_unique<BlkXored>(
				block,
				make_unique<BlkRaw>(iter->value()),
				make_unique<BlkRaw>(K1)
			),
			key
		).value();
	}

	const auto K2 = ((K1.high & 0x8000000000000000) == 0) ? (K1 << 1) : (K1 << 1) ^ B;
	return BlkEncrypted(
		make_unique<BlkXored>(
			block,
			make_unique<BlkRaw>(iter->value()),
			make_unique<BlkRaw>(K2)
		),
		key
	).value();
}
