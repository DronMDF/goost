#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "KeyData.h"

namespace magma {

class Block;
class Sbox;

class Key {
public:
	explicit Key(const std::string &key_data);
	Key(const std::string &key_data, const std::shared_ptr<const Sbox> &sbox);
	Key(std::unique_ptr<const KeyData> key_data, const std::shared_ptr<const Sbox> &sbox);

	Block forward(const Block &block) const;
	Block backward(const Block &block) const;

private:
	uint32_t cycle(uint32_t v, int index) const;

	const std::unique_ptr<const KeyData> key_data;
	const std::shared_ptr<const Sbox> sbox;
};

}
