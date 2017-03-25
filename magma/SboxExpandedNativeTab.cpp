#include "SboxExpandedNativeTab.h"

using namespace std;
using namespace magma;

SboxExpandedNativeTab::SboxExpandedNativeTab(const vector<uint32_t> &tab)
	: tab(tab)
{
}

uint32_t SboxExpandedNativeTab::translate(int index) const
{
	return tab[index & 0xff];
}
