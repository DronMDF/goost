// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

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

}  // namespace magma
