// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSink.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <goost/magma/BlkEncrypted.h>
#include <goost/magma/BlkRaw.h>
#include <goost/magma/Block.h>

using namespace std;
using namespace goost;
using namespace goost::gost89;
using namespace goost::magma;

CFBSink::CFBSink(
	const shared_ptr<const Sink> &sink,
	const shared_ptr<const Key> &key,
	uint64_t iv,
	const vector<byte> &plain
) : sink(sink), key(key), iv(iv), plain(plain)
{
}

CFBSink::CFBSink(
	const shared_ptr<const Sink> &sink,
	const shared_ptr<const Key> &key,
	uint64_t iv
) : CFBSink(sink, key, iv, {})
{
}

shared_ptr<const Sink> CFBSink::write(const vector<byte> &data) const
{
	auto s = sink;
	auto p = plain;
	auto l = iv;
	for (const auto &b : data) {
		p.push_back(b);
		if (p.size() == Block::size) {
			const auto e = BlkEncrypted(
				make_shared<BlkRaw>(l),
				key
			).value();

			auto c = p;
			for (int i = 0; i < 4; i++) {
				c[0 + i] ^= static_cast<byte>(e.first >> (i * 8));
				c[4 + i] ^= static_cast<byte>(e.second >> (i * 8));
			}

			s = s->write(c);
			memcpy(&l, &c[0], sizeof(l));
			p.clear();
		}
	}
	return make_shared<CFBSink>(s, key, l, p);
}

shared_ptr<const Sink> CFBSink::finalize() const
{
	auto s = sink;
	if (!plain.empty()) {
		const auto e = BlkEncrypted(
			make_shared<BlkRaw>(iv),
			key
		).value();
		auto c = plain;
		for (int i = 0; i < 4; i++) {
			c[0 + i] ^= static_cast<byte>(e.second >> (i * 8));
			c[4 + i] ^= static_cast<byte>(e.first >> (i * 8));
		}
		s = s->write(c);
	}
	return s;
}
