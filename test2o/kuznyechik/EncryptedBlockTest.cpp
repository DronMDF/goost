// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EncryptedBlockTest.h"
#include <list>
#include <2out/ReprPrintable.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/Block.h>
#include <kuznyechik/EncryptedBlock.h>
#include <kuznyechik/Key.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

// @todo #139:15min If EncryptBlock has Block type,
//  we can introduce universal block representation instead this class
class ReprEncryptedBlock final : public Representation {
public:
	explicit ReprEncryptedBlock(const shared_ptr<EncryptedBlock> &block)
		: block(block)
	{
	}

	string asString() const override {
		return ReprPrintable<Block>(block->value()).asString();
	}
private:
	const shared_ptr<EncryptedBlock> block;
};

// @todo #139:15min Extract key to fixture.
//  Fixture conception is not complete. Can try this here.
EncryptedBlockTest::EncryptedBlockTest()
: tests(
	make_unique<TestNamed>(
		__func__,
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"R3412_A15",
				make_unique<TestEqual>(
					make_unique<ReprEncryptedBlock>(
						make_unique<EncryptedBlock>(
							Block(
								0xffeeddccbbaa9988,
								0x1122334455667700
							),
							make_unique<Key>(
								"8899aabbccddeeff0011223344556677"
								"fedcba98765432100123456789abcdef"
							)
						)
					),
					make_unique<ReprPrintable<Block>>(
						Block(0x5a468d42b9d4edcd, 0x7f679d90bebc2430)
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
