#include "KeyDataString.h"
#include <sstream>
#include "Block.h"

using namespace std;
using namespace kuznyechik;

KeyDataString::KeyDataString(const string &key_data)
	: key_data(key_data)
{
}

Block KeyDataString::low() const
{
	uint64_t hi, lo;
	istringstream in(string(key_data, 32, 32));
	in >> hex >> hi >> lo;
	return {lo, hi};
}

Block KeyDataString::high() const
{
	uint64_t hi, lo;
	istringstream in(string(key_data, 0, 32));
	in >> hex >> hi >> lo;
	return {lo, hi};
}
