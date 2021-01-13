// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>
#include <goost/magma/Sbox.h>

namespace magma {

class ReprTransformed final : public oout::Representation {
public:
	ReprTransformed(const std::shared_ptr<const goost::magma::Sbox> &sbox, uint32_t value);

	std::string asString() const override;
private:
	const std::shared_ptr<const goost::magma::Sbox> sbox;
	const uint32_t value;
};

}  // namespace magma
