#include "SboxExpanded.h"

using namespace std;
using namespace magma;

SboxExpanded::SboxExpanded(unique_ptr<const Tab> tab1,
		unique_ptr<const Tab> tab2,
		unique_ptr<const Tab> tab3,
		unique_ptr<const Tab> tab4)
	: tab1(move(tab1)), tab2(move(tab2)), tab3(move(tab3)), tab4(move(tab4))
{
}

uint32_t SboxExpanded::transform(uint32_t v) const
{
	return tab1->translate(v & 0xff) |
		tab2->translate((v >> 8) & 0xff) |
		tab3->translate((v >> 16) & 0xff) |
		tab4->translate((v >> 24) & 0xff);
}
