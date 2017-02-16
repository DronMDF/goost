#include "KeyDataString.h"
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace magma;

KeyDataString::KeyDataString(const std::string &key_data)
	: key_data(key_data)
{
}

uint32_t KeyDataString::key(int index) const
{
	if (key_data.size() != 64) {
		throw runtime_error("Wrong key size");
	}
	if (index < 0 or index > 7) {
		throw runtime_error("Wrong key index");
	}

	uint32_t value;
	istringstream in(string(key_data, index * 8, 8));
	in >> hex >> value;
	return value;
}