#pragma once
#include <cstdint>
#include <memory>
#include <vector>

namespace magma {

class Block;
class KeyData;
class Sbox;

class Key {
public:
	explicit Key(const std::string &key_data);
	Key(const std::string &key_data, const std::shared_ptr<const Sbox> &sbox);
	Key(const std::shared_ptr<const KeyData> &key_data,
		const std::shared_ptr<const Sbox> &sbox);

	Block forward(const Block &block) const;
	Block backward(const Block &block) const;

	std::vector<uint8_t> imit(const std::vector<uint8_t> &block) const;
	std::vector<uint8_t> decrypt(const std::vector<uint8_t> &block) const;

private:
	uint32_t cycle(uint32_t v, int index) const;

	const std::shared_ptr<const KeyData> key_data;
	const std::shared_ptr<const Sbox> sbox;
};

}
