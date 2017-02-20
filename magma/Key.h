#pragma once
#include <cstdint>
#include <memory>
#include <vector>

namespace magma {

class KeyData;
class Sbox;

class Key {
public:
	Key(const std::shared_ptr<const KeyData> &key_data,
		const std::shared_ptr<const Sbox> &sbox);

	std::vector<uint8_t> imit(const std::vector<uint8_t> &block) const;
	std::vector<uint8_t> encrypt(const std::vector<uint8_t> &block) const;
	std::vector<uint8_t> decrypt(const std::vector<uint8_t> &block) const;

private:
	uint32_t cycle(uint32_t v, int index) const;

	const std::shared_ptr<const KeyData> key_data;
	const std::shared_ptr<const Sbox> sbox;
};

}
