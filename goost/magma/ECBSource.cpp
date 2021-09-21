// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ECBSource.h"
#include <cstring>
#include <netinet/in.h>
#include "Container.h"
#include "BlkDecrypted.h"
#include "BlkRaw.h"
#include "LazyKey.h"
#include "SboxByte.h"
#include "SboxTwisted.h"
#include "SboxR3412.h"

using namespace std;
using namespace goost;
using namespace goost::magma;

ECBSource::ECBSource(
	const shared_ptr<const Source> &source,
	const shared_ptr<const Key> &key
) : source(source), key(key)
{
}

ECBSource::ECBSource(
	const shared_ptr<const Source> &source,
	const shared_ptr<const Container> &container
) : ECBSource(source, makeKey(container))
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
		dynamic_pointer_cast<const LazyKey>(key)
	).value();

	memcpy(&p[0], &e.first, Block::size);

	return {p, make_shared<ECBSource>(s, key)};
}

shared_ptr<const Key> ECBSource::makeKey(const shared_ptr<const Container> &container) const
{
	vector<uint32_t> key(8);
	// @todo need to use mask
	const auto ik = container->key();
	memcpy(&key[0], &ik[0], ik.size());
	for (auto &k : key) {
		k = htonl(k);
	}

	vector<uint8_t> sbox(64);
	const auto is = container->sbox();
	memcpy(&sbox[0], &is[0], is.size());

	return make_shared<LazyKey>(key, make_shared<SboxTwisted>(make_unique<SboxByte>(sbox)));
}
