#pragma once
#include "SboxExpanded.h"

namespace magma {

class SboxExpandedNativeTab final : public SboxExpanded::Tab {
public:
	explicit SboxExpandedNativeTab(const std::vector<uint32_t> &tab);

	uint32_t translate(int index) const override;
private:
	const std::vector<uint32_t> tab;
};

}
