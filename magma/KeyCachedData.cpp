#include "KeyCachedData.h"

using namespace std;
using namespace magma;

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
