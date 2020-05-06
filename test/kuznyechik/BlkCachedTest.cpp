// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkCachedTest.h"
#include <random>
#include <2out/TestNamed.h>
#include <goost/kuznyechik/BlkCached.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

class BlkRandom final : public Block {
public:
	pair<uint64_t, uint64_t> value() const override
	{
		random_device rd;
		return {rd(), rd()};
	}
};

BlkCachedTest::BlkCachedTest()
	: block(
		make_shared<BlkCached>(
			make_shared<BlkRandom>()
		)
	  ),
	  tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"BlkCached give value once and forever",
				make_shared<TestBlockEqual>(block, block)
			)
		)
	)
{
}

unique_ptr<const Result> BlkCachedTest::result() const
{
	return tests->result();
}

