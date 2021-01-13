// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SourceMatch.h"
#include <2out/CondResult.h>
#include <2out/TestResult.h>
#include <2out/Text.h>
#include "SourceText.h"

using namespace std;
using namespace oout;
using namespace goost;

SourceMatch::SourceMatch(const shared_ptr<const Source> &source)
	: source(source)
{
}

unique_ptr<const Result> SourceMatch::match(const shared_ptr<const Text> &in) const
{
	const auto origin = in->asString();
	const auto text = SourceText(source).asString();
	ostringstream message;
	message << "'" << origin << "' is hex match '" << text << "'";
	return make_unique<TestResult>(
		make_shared<CondResult>(
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
