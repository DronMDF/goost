
// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ImitTest.h"
#include <list>
#include <sstream>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/Imit.h>
#include <kuznyechik/BlkRaw.h>
#include <kuznyechik/StMemory.h>
#include <kuznyechik/Key.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

class ImitRepr final : public Representation {
public:
	ImitRepr(const shared_ptr<const Stream> &data, const shared_ptr<const Key> &key)
		: ImitRepr(make_unique<const Imit>(data, key))
	{
	}

	explicit ImitRepr(const shared_ptr<const Imit> &imit)
		: imit(imit)
	{
	}

	string asString() const override
	{
		ostringstream os;
		os << hex << imit->value().high;
		return os.str();
	}
private:
	const shared_ptr<const Imit> imit;
};

ImitTest::ImitTest()
: tests(
	make_unique<TestNamed>(
		__func__,
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"R3413_A162",
				make_unique<TestEqual>(
					make_unique<ImitRepr>(
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
					),
					"336f4d296059fbe3"
				)
			)
		}
	)
)
{
}

unique_ptr<const Result> ImitTest::result() const
{
	return tests->result();
}
