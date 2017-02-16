#pragma once
#include <cstdint>

namespace magma {

class KeyData {
public:
	virtual ~KeyData() = default;
	virtual uint32_t key(int index) const = 0;
};

}
