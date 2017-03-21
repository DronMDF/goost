#pragma once
#include "KeyData.h"
#include <memory>

namespace magma {

class KeyCachedData final : public KeyData {
public:
	explicit KeyCachedData(std::unique_ptr<const KeyData> keydata);
	uint32_t key(int index) const override;
private:
	struct CachedData {
		std::array<bool, 8> cached;
		std::array<uint32_t, 8> key;
	};
	const std::unique_ptr<CachedData> cache;
	const std::unique_ptr<const KeyData> keydata;
};

}
