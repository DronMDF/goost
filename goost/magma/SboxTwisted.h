// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Sbox.h"
#include <memory>

namespace magma {

// Sbox decorator for <<<11 operation
class SboxTwisted : public Sbox {
public:
	explicit SboxTwisted(std::unique_ptr<const Sbox> sbox);

	uint32_t transform(uint32_t value) const final;
private:
	const std::unique_ptr<const Sbox> sbox;
};

}  // namespace magma
