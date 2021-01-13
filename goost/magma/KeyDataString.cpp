// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataString.h"
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace goost::magma;

KeyDataString::KeyDataString(const std::string &key_data)
	: key_data(key_data)
{
}

uint32_t KeyDataString::key(int index) const
{
	if (key_data.size() != 64) {
		throw runtime_error("Wrong key size");
	}
	if (index < 0 || index > 7) {
		throw runtime_error("Wrong key index");
	}

	uint32_t value;
	istringstream in(string(key_data, index * 8, 8));
	in >> hex >> value;
	return value;
}
