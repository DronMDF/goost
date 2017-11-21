// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Sbox.h"
#include <cstdint>
#include <memory>
#include <vector>

namespace magma {

// This is a byte expanded sbox, not fastest.
class SboxByte final : public Sbox {
public:
	class Tab {
	public:
		virtual ~Tab() = default;
		virtual uint32_t translate(int index) const = 0;
	};

	// Ctor from collapsed sbox
	explicit SboxByte(const std::vector<uint8_t> &uz);

	// Primary ctor
	SboxByte(
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

}  // namespace magma
