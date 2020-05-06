// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprTransformed.h"
#include <sstream>
#include <iomanip>
#include <goost/magma/Sbox.h>

using namespace std;
using namespace magma;

ReprTransformed::ReprTransformed(const shared_ptr<const Sbox> &sbox, uint32_t value)
	: sbox(sbox), value(value)
{
}

string ReprTransformed::asString() const
{
	const auto result = sbox->transform(value);
	ostringstream out;
	out << hex << setfill('0') << setw(8) << result;
	return out.str();
}
