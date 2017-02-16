#pragma once
#include "KeyData.h"
#include <string>

namespace magma {

class KeyDataString : public MagmaKeyData {
public:
	explicit KeyDataString(const std::string &key_data);
	virtual uint32_t key(int index) const override;
private:
	const std::string key_data;
};

};
