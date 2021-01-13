// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <goost/magma/Sbox.h>

namespace goost {
namespace gost89 {

class TestSbox final : public goost::magma::Sbox {
public:
	TestSbox();
	uint32_t transform(uint32_t value) const override;
private:
	const std::shared_ptr<const Sbox> sbox;
};

}
}
