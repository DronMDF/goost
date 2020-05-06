// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkCached.h"

using namespace std;
using namespace kuznyechik;

class BlkCached::BlockCache final {
public:
	explicit BlockCache(const shared_ptr<const Block> &block)
		: loaded(false), state(), block(block)
	{
	}

	pair<uint64_t, uint64_t> value()
	{
		if (!loaded) {
			state = block->value();
			loaded = true;
		}
		return state;
	}
private:
	bool loaded;
	pair<uint64_t, uint64_t> state;
	const shared_ptr<const Block> block;
};

BlkCached::BlkCached(const std::shared_ptr<const Block> &block)
	: cache(make_shared<BlockCache>(block))
{
}

pair<uint64_t, uint64_t> BlkCached::value() const
{
	return cache->value();
}
