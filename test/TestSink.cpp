// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSink.h"
#include <iostream>
#include <iomanip>

using namespace std;

TestSink::TestSink(const vector<byte> &data)
	: data(data)
{
}

TestSink::TestSink()
	: TestSink(vector<byte>{})
{
}

shared_ptr<const Sink> TestSink::write(const vector<byte> &d) const
{
	auto dd = data;
	dd.insert(dd.begin(), d.begin(), d.end());
	return make_shared<TestSink>(dd);
}

shared_ptr<const Sink> TestSink::finalize() const
{
	return make_shared<TestSink>(data);
}

string TestSink::asHexString() const
{
	ostringstream out;
	for (const auto &b : data) {
		out << hex << setfill('0') << setw(2) << to_integer<unsigned>(b);
	}
	return out.str();
}
