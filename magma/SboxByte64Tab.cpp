#include "SboxByte64Tab.h"

using namespace std;
using namespace magma;

SboxByte64Tab::SboxByte64Tab(const vector<uint8_t> &uz, int offset)
	: uz(uz), offset(offset)
{
}

uint32_t SboxByte64Tab::translate(int index) const
{
	return (uz[((index >> 4) & 0xf) * 4 + offset] & 0xf0)
		+ (uz[(index & 0xf) * 4 + offset] & 0x0f);
}
