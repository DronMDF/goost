// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "KeyData.h"
#include <memory>

namespace goost {
namespace magma {

class KeyCachedData final : public KeyData {
public:
	explicit KeyCachedData(std::unique_ptr<const KeyData> keydata);
	uint32_t key(int index) const override;
private:
	struct CachedData {
		bool cached;
		std::array<uint32_t, 8> key;
	};
	const std::unique_ptr<CachedData> cache;
	const std::unique_ptr<const KeyData> keydata;
};

}  // namespace magma
}  // namespace goost
