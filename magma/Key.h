// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "KeyData.h"

namespace magma {

class BlkRaw;
class Sbox;

// @todo #274 Split magma::Key to magma::Forward and magma::Backward?
//  need to think about it.
class Key {
public:
	/// String key
	explicit Key(const std::string &key_data);
	Key(const std::string &key_data, const std::shared_ptr<const Sbox> &sbox);

	/// Native key
	Key(const std::vector<uint32_t> &key_data, const std::shared_ptr<const Sbox> &sbox);

	/// Primary ctor
	Key(std::unique_ptr<const KeyData> key_data, const std::shared_ptr<const Sbox> &sbox);

	BlkRaw forward(const BlkRaw &block) const;
	BlkRaw backward(const BlkRaw &block) const;

private:
	uint32_t cycle(uint32_t v, int index) const;

	const std::unique_ptr<const KeyData> key_data;
	const std::shared_ptr<const Sbox> sbox;
};

}
