// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ECBSource.h"
#include <cstring>
#include "BlkDecrypted.h"
#include "BlkRaw.h"

using namespace std;
using namespace goost;
using namespace goost::magma;

ECBSource::ECBSource(
	const shared_ptr<const Source> &source,
	const shared_ptr<const LazyKey> &key
) : source(source), key(key)
{
}

pair<vector<byte>, shared_ptr<const Source>> ECBSource::read(size_t size) const
{
	if (size < Block::size) {
		throw runtime_error("Unaligned ECB decryption");
	}

	auto s = source;
	vector<byte> p;
	tie(p, s) = s->read(8);
	if (p.empty()) {
		// Decryption is done
		return {p, s};
	}

	const auto e = BlkDecrypted(
		make_shared<BlkRaw>(&p[0]),
		key
	).value();

	memcpy(&p[0], &e.first, Block::size);

	return {p, make_shared<ECBSource>(s, key)};
}
