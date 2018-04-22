// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iomanip>
#include <sstream>
#include <goost/kuznyechik/Imit.h>
#include <goost/kuznyechik/StMemory.h>
#include <goost/kuznyechik/Key.h>

using namespace std;
using namespace kuznyechik;

int main(int, char **)
{
	const auto imit = make_unique<Imit>(
		make_unique<const StMemory>(
			vector<uint64_t>{
				0xffeeddccbbaa9988,
				0x1122334455667700,
				0x8899aabbcceeff0a,
				0x0011223344556677,
				0x99aabbcceeff0a00,
				0x1122334455667788,
				0xaabbcceeff0a0011,
				0x2233445566778899
			}
		),
		make_unique<const Key>(
			"8899aabbccddeeff0011223344556677"
			"fedcba98765432100123456789abcdef"
		)
	);

	const auto value = imit->value();

	ostringstream os;
	os << hex << setfill('0') << setw(16) << value.second << setw(16) << value.first;
	return os.str() == "336f4d296059fbe34ddeb35b37749c67" ? 0 : -1;
}
