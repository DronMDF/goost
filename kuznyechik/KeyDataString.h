#pragma once
#include "Key.h"
#include <string>

namespace kuznyechik {

class KeyDataString final : public Key::Data {
public:
	explicit KeyDataString(const std::string &key_data);
	Block low() const override;
	Block high() const override;
private:
	const std::string key_data;
};

}

