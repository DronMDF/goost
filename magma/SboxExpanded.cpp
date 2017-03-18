#include "SboxExpanded.h"
#include "SboxExpandedCachedTab.h"
#include "SboxExpandedNibbleTab.h"

using namespace std;
using namespace magma;

SboxExpanded::SboxExpanded(
		const std::vector<int> &p0,
		const std::vector<int> &p1,
		const std::vector<int> &p2,
		const std::vector<int> &p3,
		const std::vector<int> &p4,
		const std::vector<int> &p5,
		const std::vector<int> &p6,
		const std::vector<int> &p7
	)
	: SboxExpanded(
		make_unique<SboxExpandedCachedTab>(make_unique<SboxExpandedNibbleTab>(p0, p1, 0)),
		make_unique<SboxExpandedCachedTab>(make_unique<SboxExpandedNibbleTab>(p2, p3, 8)),
		make_unique<SboxExpandedCachedTab>(make_unique<SboxExpandedNibbleTab>(p4, p5, 16)),
		make_unique<SboxExpandedCachedTab>(make_unique<SboxExpandedNibbleTab>(p6, p7, 24))
	)
{
}

SboxExpanded::SboxExpanded(
		unique_ptr<const Tab> tab1,
		unique_ptr<const Tab> tab2,
		unique_ptr<const Tab> tab3,
		unique_ptr<const Tab> tab4
	)
	: tab1(move(tab1)), tab2(move(tab2)), tab3(move(tab3)), tab4(move(tab4))
{
}

uint32_t SboxExpanded::transform(uint32_t v) const
{
	return tab1->table()[v & 0xff] |
		tab2->table()[(v >> 8) & 0xff] |
		tab3->table()[(v >> 16) & 0xff] |
		tab4->table()[(v >> 24) & 0xff];
}
