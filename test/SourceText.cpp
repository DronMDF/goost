// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SourceText.h"
#include <cstddef>
#include <iomanip>
#include <sstream>
#include <goost/Source.h>

using namespace std;
using namespace goost;

SourceText::SourceText(const shared_ptr<const Source> &source)
	: source(source)
{
}

string SourceText::asString() const
{
	const auto [bytes, _] = source->read(numeric_limits<size_t>::max());
	ostringstream out;
	for (const auto &b : bytes) {
		out << hex << setw(2) << setfill('0') << to_integer<unsigned>(b);
	}
	return out.str();
}
