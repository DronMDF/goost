#pragma once
#include "Sbox.h"
#include <array>
#include <memory>
#include <vector>

namespace magma {

class SboxExpanded final : public Sbox {
public:
	class Tab {
	public:
		virtual ~Tab() = default;
		virtual uint32_t translate(int index) const = 0;
	};

	/// Default sbox from R3412
	SboxExpanded();

	/// Ctor from 16x8 matrix
	SboxExpanded(
		const std::vector<int> &p0,
		const std::vector<int> &p1,
		const std::vector<int> &p2,
		const std::vector<int> &p3,
		const std::vector<int> &p4,
		const std::vector<int> &p5,
		const std::vector<int> &p6,
		const std::vector<int> &p7
	);

	// Primary ctor
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
