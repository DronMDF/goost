// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Key.h"
#include <cstring>
#include "BlkRaw.h"
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

uint32_t Key::cycle(uint32_t v, int index) const
{
	return sbox->transform(key_data->key(index) + v);
}

BlkRaw Key::forward(const BlkRaw &block) const
{
	const auto value = block.value();
	uint32_t a = value.first;
	uint32_t b = value.second;

	b ^= cycle(a, 0);
	a ^= cycle(b, 1);
	b ^= cycle(a, 2);
	a ^= cycle(b, 3);
	b ^= cycle(a, 4);
	a ^= cycle(b, 5);
	b ^= cycle(a, 6);
	a ^= cycle(b, 7);

	return {a, b};
}

BlkRaw Key::backward(const BlkRaw &block) const
{
	const auto value = block.value();
	uint32_t a = value.first;
	uint32_t b = value.second;

	b ^= cycle(a, 7);
	a ^= cycle(b, 6);
	b ^= cycle(a, 5);
	a ^= cycle(b, 4);
	b ^= cycle(a, 3);
	a ^= cycle(b, 2);
	b ^= cycle(a, 1);
	a ^= cycle(b, 0);

	return {a, b};
}
