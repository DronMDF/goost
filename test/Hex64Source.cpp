// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Hex64Source.h"
#include <cctype>

using namespace std;
using namespace goost;

Hex64Source::Hex64Source(const string &str)
	: str(str)
{
}

pair<vector<byte>, shared_ptr<const Source>> Hex64Source::read(size_t size) const
{
	vector<byte> res;
	vector<char> hex;
	size_t p = 0;
	while (res.size() < size && p < str.size()) {
		const char c = str[p++];
		if (isxdigit(c)) {
			hex.push_back(c);
			if (hex.size() == 16) {
				for (int i = 7; i >= 0; i--) {
					res.push_back(
						static_cast<byte>(
							stoul(string(&hex[i * 2], 2), 0, 16)
						)
					);
				}
				hex.clear();
			}
		}
	}
	return {res, make_shared<Hex64Source>(str.substr(p))};
}
