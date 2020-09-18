// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyCachedData.h"

using namespace std;
using namespace goost::magma;

KeyCachedData::KeyCachedData(unique_ptr<const KeyData> keydata)
	: cache(make_unique<CachedData>()), keydata(move(keydata))
{
}

uint32_t KeyCachedData::key(int index) const
{
	if (!cache->cached) {
		for (size_t i = 0; i < cache->key.size(); i++) {
			cache->key[i] = keydata->key(i);
		}
		cache->cached = true;
	}
	return cache->key[index];
}
