// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataString.h"
#include <string>
#include "BlkString.h"

using namespace std;
using namespace kuznyechik;

KeyDataString::KeyDataString(const string &key_data)
	: key_data(key_data)
{
}

shared_ptr<const Block> KeyDataString::low() const
{
	return make_shared<BlkString>(string(key_data, 32, 32));
}

shared_ptr<const Block> KeyDataString::high() const
{
	return make_shared<BlkString>(string(key_data, 0, 32));
}
