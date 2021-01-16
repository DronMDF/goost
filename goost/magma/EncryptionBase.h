// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace goost {
namespace magma {

class Key;

class EncryptionBase final {
public:
	explicit EncryptionBase(const std::shared_ptr<const Key> &key);
	uint64_t transform(const uint64_t block) const;
private:
	const std::shared_ptr<const Key> key;
};

}
}
