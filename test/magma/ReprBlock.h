// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>
#include <goost/magma/Block.h>

namespace magma {

class ReprBlock final : public oout::Representation {
public:
	explicit ReprBlock(const std::shared_ptr<const goost::magma::Block> &block);
	std::string asString() const override;
private:
	const std::shared_ptr<const goost::magma::Block> block;
};

}  // namespace magma
