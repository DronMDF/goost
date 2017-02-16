#include "KeyDataNative.h"

using namespace std;
using namespace magma;

KeyDataNative::KeyDataNative(const vector<uint32_t> &key_data)
	: key_data(key_data)
{
}

uint32_t KeyDataNative::key(int index) const
{
	return key_data[index];
}
