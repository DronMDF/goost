// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "Key.h"
#include "KeyData.h"

namespace goost {
namespace magma {

class BlkRaw;
class Sbox;

class LazyKey final : public Key {
public:
	/// String key
	explicit LazyKey(const std::string &key_data);
	LazyKey(const std::string &key_data, const std::shared_ptr<const Sbox> &sbox);

	/// Native key
	LazyKey(const std::vector<uint32_t> &key_data, const std::shared_ptr<const Sbox> &sbox);

	/// Primary ctor
	LazyKey(std::unique_ptr<const KeyData> key_data, const std::shared_ptr<const Sbox> &sbox);

	uint32_t transform(uint32_t v, int index) const override;

private:
	const std::unique_ptr<const KeyData> key_data;
	const std::shared_ptr<const Sbox> sbox;
};

}  // namespace magma
}  // namespace goost
