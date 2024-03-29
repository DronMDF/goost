// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkCachedTest.h"
#include <random>
#include <2out/NamedTest.h>
#include <goost/kuznyechik/BlkCached.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
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
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
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

