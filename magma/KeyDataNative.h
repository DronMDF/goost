#pragma once
#include "KeyData.h"
#include <vector>

namespace magma {

class KeyDataNative : public KeyData {
public:
	explicit KeyDataNative(const std::vector<uint32_t> &key_data);
	uint32_t key(int index) const final;
private:
	const std::vector<uint32_t> key_data;
};

}
