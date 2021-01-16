// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EncryptionBaseTest.h"
#include <sstream>
#include <iomanip>
#include <2out/2out.h>
#include <goost/magma/EncryptionBase.h>
#include <goost/magma/LazyKey.h>

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace test::magma;

class EncryptionBaseText final : public Text {
public:
	EncryptionBaseText(const uint64_t block)
		: block(block)
	{
	}

	string asString() const override {
		EncryptionBase base(
			make_shared<LazyKey>(
				"ffeeddccbbaa99887766554433221100f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
			)
		);
		ostringstream out;
		out << hex << setw(16) << setfill('0') << base.transform(block);
		return out.str();
	}
private:
	const uint64_t block;
};

EncryptionBaseTest::EncryptionBaseTest()
: dirty::Test(
	__func__,
	make_shared<const NamedTest>(
		"R3412_A24",
		make_shared<EncryptionBaseText>(0xfedcba9876543210),
		make_shared<EqualMatch>("4ee901e5c2d8ca3d")
	),
	make_shared<const NamedTest>(
		"R3412_A262_1",
		make_shared<EncryptionBaseText>(0x92def06b3c130a59),
		make_shared<EqualMatch>("2b073f0494f372a0")
	),
	make_shared<const NamedTest>(
		"R3412_A262_2",
		make_shared<EncryptionBaseText>(0xf053f8006cebef80),
		make_shared<EqualMatch>("c89ed814fd5e18e9")
	),
	make_shared<const NamedTest>(
		"R3412_A262_3",
		make_shared<EncryptionBaseText>(0x8206233a9af61aa5),
		make_shared<EqualMatch>("f739b18d34289b00")
	),
	make_shared<const TestNamed>(
		"R3412_A262_4",
		make_shared<EncryptionBaseText>(0x216e6a2561cff165),
		make_shared<EqualMatch>("154e72102030c5bb")
	)
)
{
}
