#pragma once
#include <cstdint>

class MagmaKeyData {
public:
	virtual ~MagmaKeyData() = default;
	virtual uint32_t key(int index) const = 0;
};
