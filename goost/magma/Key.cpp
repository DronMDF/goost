// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Key.h"
#include "KeyCachedData.h"
#include "KeyData.h"
#include "KeyDataNative.h"
#include "KeyDataString.h"
#include "Sbox.h"
#include "SboxR3412.h"

using namespace std;
using namespace magma;

Key::Key(const string &key_data)
	: Key(key_data, make_shared<SboxR3412>())
{
}

Key::Key(const string &key_data, const shared_ptr<const Sbox> &sbox)
	: Key(make_unique<const KeyCachedData>(make_unique<const KeyDataString>(key_data)), sbox)
{
}

Key::Key(const vector<uint32_t> &key_data, const shared_ptr<const Sbox> &sbox)
	: Key(make_unique<const KeyDataNative>(key_data), sbox)
{
}

Key::Key(unique_ptr<const KeyData> key_data, const shared_ptr<const Sbox> &sbox)
	: key_data(move(key_data)), sbox(sbox)
{
}

uint32_t Key::transform(uint32_t v, int index) const
{
	return sbox->transform(key_data->key(index) + v);
}
