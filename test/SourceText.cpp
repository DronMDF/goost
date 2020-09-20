// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SourceText.h"

using namespace std;
using namespace goost;

SourceText::SourceText(const shared_ptr<const goost::Source> &source)
	: source(source)
{
}

string SourceText::asString() const
{
	return {};
}
