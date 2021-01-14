// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSource.h"
#include <cstring>
#include <goost/magma/BlkEncrypted.h>
#include <goost/magma/BlkRaw.h>
#include <goost/magma/LazyKey.h>

using namespace std;
using namespace goost;
using namespace goost::magma;
using namespace goost::gost89;

CFBSource::CFBSource(
	const shared_ptr<const Source> &source,
	const shared_ptr<const Key> &key,
	uint64_t iv,
	const vector<byte> &plain
) : source(source), key(key), iv(iv), plain(plain)
{
}

CFBSource::CFBSource(
	const shared_ptr<const Source> &source,
	const shared_ptr<const Key> &key,
	uint64_t iv
) : CFBSource(source, key, iv, {})
{
}

pair<vector<byte>, shared_ptr<const Source>> CFBSource::read(size_t size) const
{
	auto s = source;
	auto p = plain;
	auto r = iv;
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
			make_shared<BlkRaw>(r),
			dynamic_pointer_cast<const LazyKey>(key)
		).value();

		tie(p, s) = s->read(8);
		if (p.empty()) {
			break;
		}

		memcpy(&r, &p[0], max(sizeof(r), p.size()));

		for (size_t i = 0; i < 4; i++) {
			if (p.size() >= 0 + i) {
				p[0 + i] ^= static_cast<byte>(e.first >> (i * 8));
			}
			if (p.size() >= 4 + i) {
				p[4 + i] ^= static_cast<byte>(e.second >> (i * 8));
			}
		}
	}

	return {res, make_shared<CFBSource>(s, key, r, p)};
}
