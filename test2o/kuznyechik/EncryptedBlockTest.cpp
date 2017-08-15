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

ostream &operator << (ostream &os, const EncryptedBlock &block)
{
	os << block.value();
	return os;
}

EncryptedBlockTest::EncryptedBlockTest()
: tests(
	make_unique<TestNamed>(
		__func__,
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"R3412_A15",
				make_unique<TestEqual>(
					make_unique<ReprPrintable<EncryptedBlock>>(
						EncryptedBlock(
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

shared_ptr<const Result> EncryptedBlockTest::result() const
{
	return tests->result();
}
