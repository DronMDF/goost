// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Hex64Match.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <2out/CondResult.h>
#include <2out/TestResult.h>
#include <2out/Text.h>

using namespace std;

Hex64Match::Hex64Match(const std::string &hex)
	: hex(hex)
{
}

unique_ptr<const oout::Result> Hex64Match::match(const shared_ptr<const oout::Text> &in) const
{
	const auto origin = in->asString();
	string text;
	string hex64;
	string hex8;
	for (const auto &h : hex) {
		if (isxdigit(h)) {
			hex8 += h;
			if (hex8.length() == 2) {
				hex64.insert(0, hex8);
				hex8.clear();
				if (hex64.length() == 16) {
					text += hex64;
					hex64.clear();
				}
			}
		}
	}
	ostringstream message;
	message << "'" << origin << "' is hex match '" << text << "'";
	return make_unique<oout::TestResult>(
		make_shared<oout::CondResult>(
			equal(
				text.begin(),
				text.end(),
				origin.begin(),
				[](const auto &a, const auto &b){
					return toupper(a) == toupper(b);
				}
			),
			message.str()
		)
	);
}
