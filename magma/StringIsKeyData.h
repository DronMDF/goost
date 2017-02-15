#pragma once
#include "KeyData.h"
#include <string>

class MagmaStringIsKeyData : public MagmaKeyData {
public:
	explicit MagmaStringIsKeyData(const std::string &key_data);
	virtual uint32_t key(int index) const override;
private:
	const std::string key_data;
};
