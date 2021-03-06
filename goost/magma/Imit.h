// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"

namespace goost {
namespace magma {

class Stream;
class LazyKey;

class Imit final : public Block {
public:
	Imit(const std::shared_ptr<const Stream> &data, const std::shared_ptr<const LazyKey> &key);

	std::pair<uint32_t, uint32_t> value() const override;
private:
	const std::shared_ptr<const Stream> data;
	const std::shared_ptr<const LazyKey> key;
};

}  // namespace magma
}  // namespace goost
