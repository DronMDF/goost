// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataNative.h"

using namespace std;
using namespace magma;

KeyDataNative::KeyDataNative(const vector<uint32_t> &key_data)
	: key_data(key_data)
{
}

uint32_t KeyDataNative::key(int index) const
{
	return key_data[index];
}
