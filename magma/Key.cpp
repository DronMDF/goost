#include "Key.h"
#include <cstring>
#include "Block.h"
#include "KeyData.h"
#include "KeyDataString.h"
#include "Sbox.h"
#include "SboxR3412.h"

using namespace std;
using namespace magma;

Key::Key(const string &key_data)
	: Key(key_data, make_shared<SboxR3412>())
{
}

Key::Key(const string &key_data, const shared_ptr<const Sbox> &sbox)
	: Key(make_shared<const KeyDataString>(key_data), sbox)
{
}

Key::Key(const shared_ptr<const KeyData> &key_data, const shared_ptr<const Sbox> &sbox)
	: key_data(key_data), sbox(sbox)
{
}

uint32_t Key::cycle(uint32_t v, int index) const
{
	return sbox->transform(key_data->key(index) + v);
}

Block Key::forward(const Block &block) const
{
	uint32_t a = block.low;
	uint32_t b = block.high;

	b ^= cycle(a, 0);
	a ^= cycle(b, 1);
	b ^= cycle(a, 2);
	a ^= cycle(b, 3);
	b ^= cycle(a, 4);
	a ^= cycle(b, 5);
	b ^= cycle(a, 6);
	a ^= cycle(b, 7);

	return {a, b};
}

Block Key::backward(const Block &block) const
{
	uint32_t a = block.low;
	uint32_t b = block.high;

	b ^= cycle(a, 7);
	a ^= cycle(b, 6);
	b ^= cycle(a, 5);
	a ^= cycle(b, 4);
	b ^= cycle(a, 3);
	a ^= cycle(b, 2);
	b ^= cycle(a, 1);
	a ^= cycle(b, 0);

	return {a, b};
}

vector<uint8_t> Key::imit(const vector<uint8_t> &block) const
{
	if (block.size() != 8) {
		throw runtime_error("Wrong block size");
	}

	const auto rb = forward(forward(Block{&block[0]}));

	vector<uint8_t> rv(8);
	reinterpret_cast<uint32_t *>(&rv[0])[1] = rb.high;
	reinterpret_cast<uint32_t *>(&rv[0])[0] = rb.low;
	return rv;
}

vector<uint8_t> Key::decrypt(const vector<uint8_t> &block) const
{
	if (block.size() != 8) {
		throw runtime_error("Wrong block size");
	}

	const auto rb = backward(backward(backward(forward(Block{&block[0]}))));

	vector<uint8_t> rv(8);
	reinterpret_cast<uint32_t *>(&rv[0])[0] = rb.high;
	reinterpret_cast<uint32_t *>(&rv[0])[1] = rb.low;
	return rv;
}
