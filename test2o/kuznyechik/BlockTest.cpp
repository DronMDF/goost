// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockTest.h"
#include <sstream>
#include <list>
#include <2out/Representation.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/Block.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

// @todo #128:15min Replace BlockRepr to oout::ReprPrintable
class BlockRepr final : public Representation {
public:
	explicit BlockRepr(const shared_ptr<const Block> &block)
		: block(block)
	{
	}

	string asString() const override
	{
		ostringstream os;
		os << *block;
		return os.str();
	}
private:
	const shared_ptr<const Block> block;
};

BlockTest::BlockTest()
: tests(
	make_unique<TestNamed>(
		__func__,
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"ByteOrder",
				make_unique<TestEqual>(
					make_unique<BlockRepr>(
						make_unique<Block>(1)
					),
					"00000000000000000000000000000001"
				)
			)
		}
	)
)
{
}

shared_ptr<const Result> BlockTest::result() const
{
	return tests->result();
}
