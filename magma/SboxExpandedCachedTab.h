#pragma once
#include "SboxExpanded.h"

namespace magma {

class SboxExpandedCachedTab final : public SboxExpanded::Tab {
public:
	explicit SboxExpandedCachedTab(std::unique_ptr<SboxExpanded::Tab> tab);

	virtual uint32_t translate(int index) const override;
private:
	struct CachedTab {
		CachedTab();
		bool cached;
		std::array<uint32_t, 256> tab;
	};
	const std::unique_ptr<CachedTab> cache;
	const std::unique_ptr<const SboxExpanded::Tab> tab;
};

}
