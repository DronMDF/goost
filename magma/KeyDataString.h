#pragma once
#include "KeyData.h"
#include <string>

namespace magma {

class KeyDataString : public KeyData {
public:
	explicit KeyDataString(const std::string &key_data);
	uint32_t key(int index) const final;
private:
	const std::string key_data;
};

}
