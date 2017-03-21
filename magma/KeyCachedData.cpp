#include "KeyCachedData.h"

using namespace std;
using namespace magma;

KeyCachedData::KeyCachedData(unique_ptr<const KeyData> keydata)
	: cache(make_unique<CachedData>()), keydata(move(keydata))
{
}

uint32_t KeyCachedData::key(int index) const
{
	if (!cache->cached[index]) {
		cache->key[index] = keydata->key(index);
		cache->cached[index] = true;
	}
	return cache->key[index];
}
