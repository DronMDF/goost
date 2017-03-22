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

uint32_t SboxExpandedNibbleTab::translate(int index) const
{
	const auto l = index & 0xf;
	const auto h = (index >> 4) & 0xf;
	const auto b = ((ph[h] << 4) | pl[l]) << shift;
	return (b << 11) | ((b >> 21) & 0x7ff);
}
