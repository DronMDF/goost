#pragma once
#include "Sbox.h"
#include <vector>

namespace magma {

class SboxNibble : public Sbox {
public:
	SboxNibble(const std::vector<int> &p0,
		const std::vector<int> &p1,
		const std::vector<int> &p2,
		const std::vector<int> &p3,
		const std::vector<int> &p4,
		const std::vector<int> &p5,
		const std::vector<int> &p6,
		const std::vector<int> &p7);

	uint32_t transform(uint32_t value) const final;

private:
	const std::vector<int> p0;
	const std::vector<int> p1;
	const std::vector<int> p2;
	const std::vector<int> p3;
	const std::vector<int> p4;
	const std::vector<int> p5;
	const std::vector<int> p6;
	const std::vector<int> p7;

	uint32_t transformN(uint32_t value, const std::vector<int> &p, int nidx) const;
};

}
