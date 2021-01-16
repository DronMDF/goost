// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ECBSink.h"
#include <cstring>
#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "Block.h"
#include "LazyKey.h"

using namespace std;
using namespace goost;
using namespace goost::magma;

ECBSink::ECBSink(
	const shared_ptr<const Sink> &sink,
	const shared_ptr<const Key> &key
) : sink(sink), key(key)
{
}

shared_ptr<const Sink> ECBSink::write(const vector<byte> &data) const
{
	vector<byte> p;
	auto s = sink;
	for (const auto &b : data) {
		p.push_back(b);
		if (p.size() == Block::size) {
			const auto e = BlkEncrypted(
				make_shared<BlkRaw>(&p[0]),
				dynamic_pointer_cast<const LazyKey>(key)
			).value();

			memcpy(&p[0], &e.first, Block::size);

			s = s->write(p);
			p.clear();
		}
	}
	if (!p.empty()) {
		throw runtime_error("Unaligned ECB encryption");
	}
	return make_shared<ECBSink>(s, key);
}

shared_ptr<const Sink> ECBSink::finalize() const
{
	return sink;
}

