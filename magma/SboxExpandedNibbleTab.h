#pragma once
#include "SboxExpanded.h"

namespace magma {

class SboxExpandedNibbleTab final : public SboxExpanded::Tab {
public:
	SboxExpandedNibbleTab(const std::vector<int> &pl, const std::vector<int> &ph, int shift);

	virtual uint32_t translate(int index) const override;
private:
	const std::vector<int> pl;
	const std::vector<int> ph;
	const int shift;
};

}
