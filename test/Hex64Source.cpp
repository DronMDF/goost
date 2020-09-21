// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Hex64Source.h"

using namespace std;
using namespace goost;

Hex64Source::Hex64Source(const string &str)
	: str(str)
{
}

pair<vector<byte>, shared_ptr<const Source>> Hex64Source::read(size_t size) const
{
	vector<byte> res;
	size_t i = 0;
	size_t j = 0;
	while (res.size() < size) {
		byte b = static_cast<byte>(stoul(str.substr(i + 14 - j, 2), 0, 16));
		res.push_back(b);
		j += 2;
		if (j == 16) {
			j = 0;
			i += 16;
		}
		if (i == str.length()) {
			break;
		}
	}
	return {res, make_shared<Hex64Source>(string{})};
}
