#include "SboxExpandedCachedTab.h"

using namespace std;
using namespace magma;

SboxExpandedCachedTab::CachedTab::CachedTab()
	: cached(false)
{
}

SboxExpandedCachedTab::SboxExpandedCachedTab(unique_ptr<SboxExpanded::Tab> tab)
	: cache(make_unique<CachedTab>()), tab(move(tab))
{
}

array<uint32_t, 256> SboxExpandedCachedTab::table() const
{
	if (!cache->cached) {
		cache->tab = tab->table();
		cache->cached = true;
	}
	return cache->tab;
}
