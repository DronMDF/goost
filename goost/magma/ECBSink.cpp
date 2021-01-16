// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ECBSink.h"
#include <cstring>
#include <stdexcept>
#include "EncryptionBase.h"

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
		if (p.size() == 8) {
			const auto e = EncryptionBase(key).transform(
				*reinterpret_cast<const uint64_t *>(&p[0])
			);

			memcpy(&p[0], &e, 8);

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

