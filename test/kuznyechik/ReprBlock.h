// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

namespace kuznyechik {

class Block;

class ReprBlock final : public oout::Representation {
public:
	explicit ReprBlock(const std::shared_ptr<const Block> &block);
	std::string asString() const override;
private:
	const std::shared_ptr<const Block> block;
};

}  // namespace kuznyechik
