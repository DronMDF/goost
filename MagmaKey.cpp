#include "MagmaKey.h"
#include <cstring>
#include "MagmaSbox.h"

using namespace std;

MagmaKey::MagmaKey(const vector<uint8_t> &key, const shared_ptr<const MagmaSbox> &sbox)
	: MagmaKey(MagmaKey::fromBytes(key), sbox)
{
}

MagmaKey::MagmaKey(const vector<uint32_t> &key, const shared_ptr<const MagmaSbox> &sbox)
	: key(key), sbox(sbox)
{
}

uint32_t MagmaKey::cycle(uint32_t v, int index) const
{
	return sbox->transform(key[index] + v);
}

vector<uint8_t> MagmaKey::imit(const vector<uint8_t> &block) const
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

vector<uint32_t> MagmaKey::fromBytes(const vector<uint8_t> &key)
{
	if (key.size() != 32) {
		throw runtime_error("Wrong key size");
	}
	vector<uint32_t> rk(8);
	memcpy(&rk[0], &key[0], 32);
	return rk;
}
