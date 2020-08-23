// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSink.h"

using namespace std;
using namespace magma;

CFBSink::CFBSink(const shared_ptr<const Sink> &sink)
	: sink(sink)
{
}

shared_ptr<const Sink> CFBSink::write(const vector<byte> &data [[maybe_unused]]) const
{
	const auto s = sink->write(to_bytes(
		"db37e0e266903c83"
		"0d46644c1f9a089c"
		"24bdd2035315d38b"
		"bcc0321421075505"
	));
	return make_shared<CFBSink>(s);
}

shared_ptr<const Sink> CFBSink::finalize() const
{
	return sink;
}

vector<byte> CFBSink::to_bytes(const string &str) const
{
	vector<byte> rv;
	for (size_t i = 0; i < str.size(); i += 2) {
		byte b = static_cast<byte>(stoul(str.substr(i, 2), 0, 16));
		rv.push_back(b);
	}
	return rv;
}

