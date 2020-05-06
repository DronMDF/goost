// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StCTREncryptedTest.h"
#include <2out/TestNamed.h>
#include <goost/kuznyechik/BlkRaw.h>
#include <goost/kuznyechik/Iterator.h>
#include <goost/kuznyechik/Key.h>
#include <goost/kuznyechik/StCTREncrypted.h>
#include <goost/kuznyechik/StMemory.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

// @todo #323 introduce kuznyechik::ReprStream for testing
class BlkOfStream final : public Block {
public:
	BlkOfStream(const shared_ptr<const Stream> &stream, size_t n)
		: stream(stream), n(n)
	{
	}

	pair<uint64_t, uint64_t> value() const override
	{
		shared_ptr<const Iterator> it = stream->iter();
		for (size_t i = 0; i < n; i++) {
			it = it->next();
		}
		return it->value();
	}

private:
	const shared_ptr<const Stream> stream;
	size_t n;
};

StCTREncryptedTest::StCTREncryptedTest()
	: stream(
		make_unique<StCTREncrypted>(
			make_shared<StMemory>(
				vector<uint64_t>{
					0xffeeddccbbaa9988, 0x1122334455667700,
					0x8899aabbcceeff0a, 0x0011223344556677,
					0x99aabbcceeff0a00, 0x1122334455667788,
					0xaabbcceeff0a0011, 0x2233445566778899
				}
			),
			make_shared<Key>(
				"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
			),
			0x1234567890abcef0
		)
	  ),
	  tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"R3413_A121_1",
				make_shared<TestBlockEqual>(
					make_shared<BlkOfStream>(stream, 0),
					"f195d8bec10ed1dbd57b5fa240bda1b8"
				)
			),
			make_shared<TestNamed>(
				"R3412_A121_2",
				make_shared<TestBlockEqual>(
					make_shared<BlkOfStream>(stream, 1),
					"85eee733f6a13e5df33ce4b33c45dee4"
				)
			),
			make_shared<TestNamed>(
				"R3412_A121_3",
				make_shared<TestBlockEqual>(
					make_shared<BlkOfStream>(stream, 2),
					"a5eae88be6356ed3d5e877f13564a3a5"
				)
			),
			make_shared<TestNamed>(
				"R3412_A121_4",
				make_shared<TestBlockEqual>(
					make_shared<BlkOfStream>(stream, 3),
					"cb91fab1f20cbab6d1c6d15820bdba73"
				)
			)
		)
	)
{
}

unique_ptr<const Result> StCTREncryptedTest::result() const
{
	return tests->result();
}
