// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "HexMatch.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <2out/CondResult.h>
#include <2out/TestResult.h>
#include <2out/Text.h>

using namespace std;

HexMatch::HexMatch(const std::string &hex)
	: hex(hex)
{
}

unique_ptr<const oout::Result> HexMatch::match(const shared_ptr<const oout::Text> &in) const
{
	const auto origin = in->asString();
	string text;
	copy_if(
		hex.begin(),
		hex.end(),
		back_inserter(text),
		[](const auto c){ return isxdigit(c); }
	);
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
