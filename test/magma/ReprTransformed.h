// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

namespace magma {

class Sbox;

class ReprTransformed final : public oout::Representation {
public:
	ReprTransformed(const std::shared_ptr<const Sbox> &sbox, uint32_t value);

	std::string asString() const override;
private:
	const std::shared_ptr<const Sbox> sbox;
	const uint32_t value;
};

}