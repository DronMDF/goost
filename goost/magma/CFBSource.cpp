// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSource.h"
#include <cstring>
#include "BlkEncrypted.h"
#include "BlkRaw.h"

using namespace std;
using namespace goost;
using namespace goost::magma;

CFBSource::CFBSource(
	const shared_ptr<const Source> &source,
	const shared_ptr<const LazyKey> &key,
	uint64_t ivl,
	uint64_t ivr,
	const vector<byte> &plain
) : source(source), key(key), ivl(ivl), ivr(ivr), plain(plain)
{
}

CFBSource::CFBSource(
	const shared_ptr<const Source> &source,
	const shared_ptr<const LazyKey> &key,
	uint64_t ivl,
	uint64_t ivr
) : CFBSource(source, key, ivl, ivr, {})
{
}

pair<vector<byte>, shared_ptr<const Source>> CFBSource::read(size_t size) const
{
	auto s = source;
	auto p = plain;
	auto rl = ivl;
	auto rr = ivr;
	vector<byte> res;

	while (res.size() < size) {
		while (!p.empty() && res.size() < size) {
			res.push_back(p.front());
			p.erase(p.begin());
		}

		if (res.size() == size) {
			break;
		}

		const auto e = BlkEncrypted(
			make_shared<BlkRaw>(rl),
			key
		).value();

		tie(p, s) = s->read(8);
		if (p.empty()) {
			break;
		}

		rl = rr;
		memcpy(&rr, &p[0], max(sizeof(rr), p.size()));

		for (size_t i = 0; i < 4; i++) {
			if (p.size() >= 0 + i) {
				p[0 + i] ^= static_cast<byte>(e.first >> (i * 8));
			}
			if (p.size() >= 4 + i) {
				p[4 + i] ^= static_cast<byte>(e.second >> (i * 8));
			}
		}
	}

	return {res, make_shared<CFBSource>(s, key, rl, rr, p)};
}
