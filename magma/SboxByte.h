#pragma once
#include "Sbox.h"
#include <cstdint>
#include <vector>

namespace magma {

// This is a byte expanded sbox, not fastest.
class SboxByte : public Sbox {
public:
	SboxByte(const std::vector<uint8_t> &uz);
	SboxByte(const std::vector<uint8_t> &tab1, const std::vector<uint8_t> &tab2,
		const std::vector<uint8_t> &tab3, const std::vector<uint8_t> &tab4);

	virtual uint32_t transform(uint32_t v) const override;

private:
	static std::vector<uint8_t> expand_tab(const std::vector<uint8_t> &uz, int offset);

	const std::vector<uint8_t> tab1;
	const std::vector<uint8_t> tab2;
	const std::vector<uint8_t> tab3;
	const std::vector<uint8_t> tab4;
};

}