#include "SboxTwisted.h"

using namespace std;
using namespace magma;

SboxTwisted::SboxTwisted(const shared_ptr<const Sbox> &sbox)
	: sbox(sbox)
{
}

uint32_t SboxTwisted::transform(uint32_t value) const
{
	const auto tmp = sbox->transform(value);
	return (tmp << 11) | ((tmp >> 21) & 0x7ff);
}
