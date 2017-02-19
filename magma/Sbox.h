#pragma once
#include <cstdint>

namespace magma {

class Sbox {
public:
	virtual ~Sbox() = default;
	virtual uint32_t transform(uint32_t value) const = 0;
};

}
