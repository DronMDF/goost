// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "LazyKey.h"
#include "KeyCachedData.h"
#include "KeyData.h"
#include "KeyDataNative.h"
#include "KeyDataString.h"
#include "Sbox.h"
#include "SboxR3412.h"

using namespace std;
using namespace goost::magma;

LazyKey::LazyKey(const string &key_data)
	: LazyKey(key_data, make_shared<SboxR3412>())
{
}

LazyKey::LazyKey(const string &key_data, const shared_ptr<const Sbox> &sbox)
	: LazyKey(
		make_unique<const KeyCachedData>(make_unique<const KeyDataString>(key_data)),
		sbox
	)
{
}

LazyKey::LazyKey(const vector<uint32_t> &key_data, const shared_ptr<const Sbox> &sbox)
	: LazyKey(make_unique<const KeyDataNative>(key_data), sbox)
{
}

LazyKey::LazyKey(unique_ptr<const KeyData> key_data, const shared_ptr<const Sbox> &sbox)
	: key_data(move(key_data)), sbox(sbox)
{
}

uint32_t LazyKey::transform(uint32_t v, int index) const
{
	return sbox->transform(key_data->key(index) + v);
}
