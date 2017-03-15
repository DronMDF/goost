#pragma once
#include "Sbox.h"
#include <memory>

namespace magma {

class SboxExpanded final : public Sbox {
public:
	class Tab {
	public:
		virtual ~Tab() = default;
		virtual uint32_t translate(uint32_t v) const = 0;
	};

	SboxExpanded(
		std::unique_ptr<const Tab> tab1,
		std::unique_ptr<const Tab> tab2,
		std::unique_ptr<const Tab> tab3,
		std::unique_ptr<const Tab> tab4
	);

	uint32_t transform(uint32_t v) const override;

private:
	const std::unique_ptr<const Tab> tab1;
	const std::unique_ptr<const Tab> tab2;
	const std::unique_ptr<const Tab> tab3;
	const std::unique_ptr<const Tab> tab4;
};

}
