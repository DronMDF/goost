#include "upp11.h"

using namespace std;

UP_SUITE_BEGIN(ProceduralImitTest)

class Key final {
public:
	Key(const void *key) {
		memcpy(key_, key, sizeof(key_));
		memset(mask_, 0, sizeof(mask_));
	}

	virtual void set_sbox(const void *box) {
		const uint8_t *sptr = static_cast<const uint8_t *>(box);
		expand_tab(sptr, 0, &sbox[0]);
		expand_tab(sptr, 1, &sbox[256]);
		expand_tab(sptr, 2, &sbox[512]);
		expand_tab(sptr, 3, &sbox[768]);
	}
private:
	friend class ImitContext;

	void expand_tab(const uint8_t sbox[64], size_t offset, uint8_t tab[256]) {
		for (size_t i = 0; i < 256; i++) {
			tab[i] = (sbox[(i / 16) * 4 + offset] & 0xf0)
				+ (sbox[(i % 16) * 4 + offset] & 0x0f);
		}
	}

	uint32_t key_[8];
	uint32_t mask_[8];
	array<uint8_t, 1024> sbox;
};

class ImitContext final {
public:
	ImitContext(const Key *key)
		: key_(key), blocks(0)
	{
		memset(state, 0, sizeof(state));
	}

	void imit(const void *data, size_t len, int expand = 0)
	{
		if (len % 8 != 0 && !expand) {
			throw length_error("Imit::imit(): data length isn't "
					"multiple of block size");
		}

		const uint8_t *ptr = static_cast<const uint8_t *>(data);

		while (len >= 8) {
			for (int i = 0; i < 8; i++) {
				state[i] ^= ptr[i];
			}

			imit_block(state);
			blocks++;
			ptr += 8;
			len -= 8;
		}

		if (len != 0) {
			for (size_t i = 0; i < len; i++) {
				state[i] ^= ptr[i];
			}

			imit_block(state);
			blocks++;
		}
	}

	uint32_t result()
	{
		check_two_blocks();
		uint32_t result;
		memcpy(&result, &state[0], sizeof(result));
		return result;
	}

private:
	void check_two_blocks() {
		while (blocks < 2) {
			imit_block(state);
			blocks++;
		}
	}

	void cycle(uint32_t &half1, uint32_t &half2,
		 const uint32_t key, const uint32_t mask) const
	{
		uint32_t tmp1 = key + half2 - mask;
		uint32_t tmp2 = key_->sbox[tmp1 & 0xff];
		tmp2 |= (key_->sbox[256 + ((tmp1 >> 8) & 0xff)]) << 8;
		tmp2 |= (key_->sbox[512 + ((tmp1 >> 16) & 0xff)]) << 16;
		tmp2 |= (key_->sbox[768 + ((tmp1 >> 24) & 0xff)]) << 24;
		tmp2 = (tmp2 << 11) | ((tmp2 >> 21) & 0x7ff);

		half1 ^= tmp2;
	}

	void imit_block(void *block) const {
		uint32_t a = ((uint32_t *)block)[1];
		uint32_t b = ((uint32_t *)block)[0];
		const uint32_t *ekey = key_->key_;
		const uint32_t *emask = key_->mask_;

		cycle(a, b, ekey[0], emask[0]);
		cycle(b, a, ekey[1], emask[1]);
		cycle(a, b, ekey[2], emask[2]);
		cycle(b, a, ekey[3], emask[3]);
		cycle(a, b, ekey[4], emask[4]);
		cycle(b, a, ekey[5], emask[5]);
		cycle(a, b, ekey[6], emask[6]);
		cycle(b, a, ekey[7], emask[7]);

		cycle(a, b, ekey[0], emask[0]);
		cycle(b, a, ekey[1], emask[1]);
		cycle(a, b, ekey[2], emask[2]);
		cycle(b, a, ekey[3], emask[3]);
		cycle(a, b, ekey[4], emask[4]);
		cycle(b, a, ekey[5], emask[5]);
		cycle(a, b, ekey[6], emask[6]);
		cycle(b, a, ekey[7], emask[7]);

		((uint32_t *)block)[1] = a;
		((uint32_t *)block)[0] = b;
	}

	const Key *key_;
	uint8_t state[8];
	size_t blocks;
};

UP_TEST(Benchmark100M)
{
	// Given
	const vector<uint8_t> data(100000000U, 'A');
	vector<uint32_t> keydata = {
		0xE0F67504U,
		0xFAFB3850U,
		0x90C3C7D2U,
		0x3DCAB3EDU,
		0x42124715U,
		0x8A1EAE91U,
		0x9ECD792FU,
		0xBDEFBCD2U
	};
	vector<uint8_t> sbox{
		0xc4, 0xed, 0x83, 0xc9, 0x92, 0x98, 0xfe, 0x6b,
		0xff, 0xbe, 0x65, 0x5c, 0xe5, 0x2c, 0xb9, 0x20,
		0x89, 0x57, 0x16, 0xb3, 0x11, 0xf3, 0x98, 0x06,
		0x30, 0x79, 0xc0, 0x97, 0xa8, 0x1a, 0x5d, 0xd5,
		0x2e, 0x01, 0xda, 0x34, 0x73, 0xd5, 0x3b, 0xe8,
		0x4b, 0xc2, 0x77, 0x7e, 0xdc, 0x64, 0xac, 0xaf,
		0x6d, 0xa6, 0x02, 0xf1, 0x07, 0x4f, 0xe1, 0x4a,
		0xba, 0x30, 0x2f, 0x12, 0x56, 0x8b, 0x44, 0x8d
	};
	Key key(&keydata[0]);
	key.set_sbox(&sbox[0]);
	ImitContext imit(&key);
	// When
	imit.imit(&data[0], data.size());
	// Then
	UP_ASSERT_EQUAL(imit.result(), 2148187304);
}

UP_SUITE_END()
