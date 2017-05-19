// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataString.h"
#include <string>
#include "Block.h"

using namespace std;
using namespace kuznyechik;

KeyDataString::KeyDataString(const string &key_data)
	: key_data(key_data)
{
}

Block KeyDataString::low() const
{
	size_t pos;
	return {
		stoull(string(key_data, 48, 16), &pos, 16),
		stoull(string(key_data, 32, 16), &pos, 16),
	};
}

Block KeyDataString::high() const
{
	size_t pos;
	return {
		stoull(string(key_data, 16, 16), &pos, 16),
		stoull(string(key_data, 0, 16), &pos, 16),
	};
}
