// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestBlockEqual.h"
#include <2out/EqualMatch.h>
#include <2out/MatchTest.h>
#include <2out/Result.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

TestBlockEqual::TestBlockEqual(const shared_ptr<const Text> &a, const string &b)
	: test(make_shared<MatchTest>(a, make_shared<EqualMatch>(b)))
{
}

TestBlockEqual::TestBlockEqual(
	const shared_ptr<const Block> &a,
	const shared_ptr<const Block> &b
) : TestBlockEqual(make_shared<ReprBlock>(a), ReprBlock(b).asString())
{
}

TestBlockEqual::TestBlockEqual(const shared_ptr<const Block> &a, const string &b)
	: TestBlockEqual(make_shared<ReprBlock>(a), b)
{
}

unique_ptr<const Result> TestBlockEqual::result() const
{
	return test->result();
}
