#include "SboxByte.h"
#include <stdexcept>

using namespace std;
using namespace magma;

SboxByte::SboxByte(const std::vector<uint8_t> &uz)
	: SboxByte(SboxByte::expand_tab(uz, 0), SboxByte::expand_tab(uz, 1),
		SboxByte::expand_tab(uz, 2), SboxByte::expand_tab(uz, 3))
{
}

SboxByte::SboxByte(const vector<uint8_t> &tab1, const vector<uint8_t> &tab2,
		const vector<uint8_t> &tab3, const vector<uint8_t> &tab4)
	: tab1(tab1), tab2(tab2), tab3(tab3), tab4(tab4)
{
}

uint32_t SboxByte::transform(uint32_t v) const
{
	const uint32_t tmp = tab1[v & 0xff] |
		(tab2[(v >> 8) & 0xff] << 8) |
		(tab3[(v >> 16) & 0xff] << 16) |
		(tab4[(v >> 24) & 0xff]) << 24;
	return (tmp << 11) | ((tmp >> 21) & 0x7ff);
}

vector<uint8_t> SboxByte::expand_tab(const vector<uint8_t> &uz, int offset)
{
	if (uz.size() != 64) {
		throw runtime_error("Wrong uz size");
	}
	vector<uint8_t> tab(256);
	for (size_t i = 0; i < tab.size(); i++) {
		tab[i] = (uz[(i / 16) * 4 + offset] & 0xf0)
			+ (uz[(i % 16) * 4 + offset] & 0x0f);
	}
	return tab;
}
