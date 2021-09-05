// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkRawTest.h"
#include <2out/NamedTest.h>
#include <goost/kuznyechik/BlkRaw.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkRawTest::BlkRawTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"ByteOrder",
				make_shared<TestBlockEqual>(
					make_unique<BlkRaw>(1),
					"00000000000000000000000000000001"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkRawTest::result() const
{
	return tests->result();
}
