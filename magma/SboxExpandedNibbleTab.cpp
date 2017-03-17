#include "SboxExpandedNibbleTab.h"

using namespace std;
using namespace magma;

SboxExpandedNibbleTab::SboxExpandedNibbleTab(
		const vector<int> &pl,
		const vector<int> &ph,
		int shift
	)
	: pl(pl), ph(ph), shift(shift)
{
}

array<uint32_t, 256> SboxExpandedNibbleTab::table() const
{
	array<uint32_t, 256> tab;
	for (int l = 0; l < 16; l++) {
		for (int h = 0; h < 16; h++) {
			const auto b = ((ph[h] << 4) | pl[l]) << shift;
			tab[h * 16 + l] = (b << 11) | ((b >> 21) & 0x7ff);
		}
	}
	return tab;
}
