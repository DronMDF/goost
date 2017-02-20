#include "Key.h"
#include <cstring>
#include "KeyData.h"
#include "Sbox.h"

using namespace std;
using namespace magma;

Key::Key(const shared_ptr<const KeyData> &key_data, const shared_ptr<const Sbox> &sbox)
	: key_data(key_data), sbox(sbox)
{
}

uint32_t Key::cycle(uint32_t v, int index) const
{
	return sbox->transform(key_data->key(index) + v);
}

vector<uint8_t> Key::imit(const vector<uint8_t> &block) const
{
	if (block.size() != 8) {
		throw runtime_error("Wrong block size");
	}
	uint32_t a = reinterpret_cast<const uint32_t *>(&block[0])[1];
	uint32_t b = reinterpret_cast<const uint32_t *>(&block[0])[0];

	a ^= cycle(b, 0);
	b ^= cycle(a, 1);
	a ^= cycle(b, 2);
	b ^= cycle(a, 3);
	a ^= cycle(b, 4);
	b ^= cycle(a, 5);
	a ^= cycle(b, 6);
	b ^= cycle(a, 7);

	a ^= cycle(b, 0);
	b ^= cycle(a, 1);
	a ^= cycle(b, 2);
	b ^= cycle(a, 3);
	a ^= cycle(b, 4);
	b ^= cycle(a, 5);
	a ^= cycle(b, 6);
	b ^= cycle(a, 7);

	vector<uint8_t> rv(8);
	reinterpret_cast<uint32_t *>(&rv[0])[1] = a;
	reinterpret_cast<uint32_t *>(&rv[0])[0] = b;
	return rv;
}

vector<uint8_t> Key::encrypt(const vector<uint8_t> &block) const
{
	if (block.size() != 8) {
		throw runtime_error("Wrong block size");
	}
	uint32_t a = reinterpret_cast<const uint32_t *>(&block[0])[1];
	uint32_t b = reinterpret_cast<const uint32_t *>(&block[0])[0];

	a ^= cycle(b, 0);
	b ^= cycle(a, 1);
	a ^= cycle(b, 2);
	b ^= cycle(a, 3);
	a ^= cycle(b, 4);
	b ^= cycle(a, 5);
	a ^= cycle(b, 6);
	b ^= cycle(a, 7);

	a ^= cycle(b, 0);
	b ^= cycle(a, 1);
	a ^= cycle(b, 2);
	b ^= cycle(a, 3);
	a ^= cycle(b, 4);
	b ^= cycle(a, 5);
	a ^= cycle(b, 6);
	b ^= cycle(a, 7);

	a ^= cycle(b, 0);
	b ^= cycle(a, 1);
	a ^= cycle(b, 2);
	b ^= cycle(a, 3);
	a ^= cycle(b, 4);
	b ^= cycle(a, 5);
	a ^= cycle(b, 6);
	b ^= cycle(a, 7);

	a ^= cycle(b, 7);
	b ^= cycle(a, 6);
	a ^= cycle(b, 5);
	b ^= cycle(a, 4);
	a ^= cycle(b, 3);
	b ^= cycle(a, 2);
	a ^= cycle(b, 1);
	b ^= cycle(a, 0);

	vector<uint8_t> rv(8);
	reinterpret_cast<uint32_t *>(&rv[0])[0] = a;
	reinterpret_cast<uint32_t *>(&rv[0])[1] = b;
	return rv;
}
