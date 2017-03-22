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

uint32_t SboxExpandedCachedTab::translate(int index) const
{
	if (!cache->cached) {
		for (size_t i = 0; i < cache->tab.size(); i++) {
			cache->tab[i] = tab->translate(i);
		}
		cache->cached = true;
	}
	return cache->tab[index & 0xff];
}
