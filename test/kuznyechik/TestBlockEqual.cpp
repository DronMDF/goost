// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestBlockEqual.h"
#include <2out/ReprString.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

TestBlockEqual::TestBlockEqual(
	const shared_ptr<const Representation> &a,
	const shared_ptr<const Representation> &b
) : test(make_shared<TestEqual>(a, b))
{
}

TestBlockEqual::TestBlockEqual(
	const shared_ptr<const Block> &a,
	const shared_ptr<const Block> &b
) : TestBlockEqual(make_shared<ReprBlock>(a), make_shared<ReprBlock>(b))
{
}

TestBlockEqual::TestBlockEqual(const shared_ptr<const Block> &a, const string &b)
	: TestBlockEqual(make_shared<ReprBlock>(a), make_shared<ReprString>(b))
{
}

unique_ptr<const Result> TestBlockEqual::result() const
{
	return test->result();
}
