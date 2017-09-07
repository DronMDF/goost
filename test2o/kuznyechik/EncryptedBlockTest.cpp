// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EncryptedBlockTest.h"
#include <list>
#include <2out/ReprPrintable.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/BlkRaw.h>
#include <kuznyechik/EncryptedBlock.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

// @todo #139:15min If EncryptBlock has BlkRaw type,
//  we can introduce universal block representation instead this class
class ReprEncryptedBlock final : public Representation {
public:
	ReprEncryptedBlock(const BlkRaw &block, const shared_ptr<const Key> &key)
		: ReprEncryptedBlock(make_unique<EncryptedBlock>(block, key))
	{
	}

	explicit ReprEncryptedBlock(const shared_ptr<EncryptedBlock> &block)
		: block(block)
	{
	}

	string asString() const override {
		return ReprPrintable<BlkRaw>(block->value()).asString();
	}
private:
	const shared_ptr<EncryptedBlock> block;
};

EncryptedBlockTest::EncryptedBlockTest()
: key(make_unique<Key>("8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef")),
  tests(
	make_unique<TestNamed>(
		__func__,
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"R3412_A15, R3412_A11_1",
				make_unique<TestEqual>(
					make_unique<ReprEncryptedBlock>(
						BlkRaw(0xffeeddccbbaa9988, 0x1122334455667700),
						key
					),
					make_unique<ReprPrintable<BlkRaw>>(
						BlkRaw(0x5a468d42b9d4edcd, 0x7f679d90bebc2430)
					)
				)
			),
			make_unique<TestNamed>(
				"R3412_A11_2",
				make_unique<TestEqual>(
					make_unique<ReprEncryptedBlock>(
						BlkRaw(0x8899aabbcceeff0a, 0x0011223344556677),
						key
					),
					make_unique<ReprPrintable<BlkRaw>>(
						BlkRaw(0x285452d76718d08b, 0xb429912c6e0032f9)
					)
				)
			),
			make_unique<TestNamed>(
				"R3412_A11_3",
				make_unique<TestEqual>(
					make_unique<ReprEncryptedBlock>(
						BlkRaw(0x99aabbcceeff0a00, 0x1122334455667788),
						key
					),
					make_unique<ReprPrintable<BlkRaw>>(
						BlkRaw(0xf3f5a5313bd4b157, 0xf0ca33549d247cee)
					)
				)
			),
			make_unique<TestNamed>(
				"R3412_A11_4",
				make_unique<TestEqual>(
					make_unique<ReprEncryptedBlock>(
						BlkRaw(0xaabbcceeff0a0011, 0x2233445566778899),
						key
					),
					make_unique<ReprPrintable<BlkRaw>>(
						BlkRaw(0x3a02c4c5aa8ada98, 0xd0b09ccde830b9eb)
					)
				)
			)
		}
	)
)
{
}

unique_ptr<const Result> EncryptedBlockTest::result() const
{
	return tests->result();
}
