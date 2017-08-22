// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "LBlockTest.h"
#include <list>
#include <2out/ReprPrintable.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/Block.h>
#include <kuznyechik/LBlock.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

// @todo #158 LBlock should have Block interface.
//  Then we can use Block representation
class ReprLBlock final : public Representation {
public:
	ReprLBlock(uint64_t low, uint64_t high)
		: ReprLBlock(make_unique<LBlock>(Block(low, high)))
	{
	}

	explicit ReprLBlock(const shared_ptr<const LBlock> &block)
		: block(block)
	{
	}

	string asString() const override {
		return ReprPrintable<Block>(block->value()).asString();
	}
private:
	const shared_ptr<const LBlock> block;
};

LBlockTest::LBlockTest()
: tests(
	make_unique<TestNamed>(
		__func__,
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"R3412_A13_1",
				make_unique<TestEqual>(
					make_unique<ReprLBlock>(
						0x0000000000000000, 0x64a5940000000000
					),
					make_unique<ReprPrintable<Block>>(
						Block(0xc3166e4b7fa2890d, 0xd456584dd0e3e84c)
					)
				)
			),
			make_unique<TestNamed>(
				"R3412_A13_2",
				make_unique<TestEqual>(
					make_unique<ReprLBlock>(
						0xc3166e4b7fa2890d, 0xd456584dd0e3e84c
					),
					make_unique<ReprPrintable<Block>>(
						Block(0xd42fbc4ffea5de9a, 0x79d26221b87b584c)
					)
				)
			),
			make_unique<TestNamed>(
				"R3412_A13_3",
				make_unique<TestEqual>(
					make_unique<ReprLBlock>(
						0xd42fbc4ffea5de9a, 0x79d26221b87b584c
					),
					make_unique<ReprPrintable<Block>>(
						Block(0x8b7b68f66b513c13, 0x0e93691a0cfc6040)
					)
				)
			),
			make_unique<TestNamed>(
				"R3412_A13_4",
				make_unique<TestEqual>(
					make_unique<ReprLBlock>(
						0x8b7b68f66b513c13, 0x0e93691a0cfc6040
					),
					make_unique<ReprPrintable<Block>>(
						Block(0xfd97bcb0b44b8580, 0xe6a8094fee0aa204)
					)
				)
			)
		}
	)
)
{
}

unique_ptr<const Result> LBlockTest::result() const
{
	return tests->result();
}
