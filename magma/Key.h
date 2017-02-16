#pragma once
#include <cstdint>
#include <memory>
#include <vector>

class MagmaSbox;

namespace magma {

class KeyData;

class Key {
public:
	Key(const std::shared_ptr<const KeyData> &key_data,
		const std::shared_ptr<const MagmaSbox> &sbox);

	std::vector<uint8_t> imit(const std::vector<uint8_t> &block) const;
private:
	uint32_t cycle(uint32_t v, int index) const;

	const std::shared_ptr<const KeyData> key_data;
	const std::shared_ptr<const MagmaSbox> sbox;
};

}
