// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>
#include <goost/kuznyechik/Block.h>

namespace kuznyechik {

class ReprBlock final : public oout::Representation {
public:
	explicit ReprBlock(const std::shared_ptr<const goost::kuznyechik::Block> &block);
	std::string asString() const override;
private:
	const std::shared_ptr<const goost::kuznyechik::Block> block;
};

}  // namespace kuznyechik
