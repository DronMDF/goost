// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkXoredTest.h"
#include <2out/NamedTest.h>
#include <goost/kuznyechik/BlkString.h>
#include <goost/kuznyechik/BlkXored.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkXoredTest::BlkXoredTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"Xor",
				make_shared<TestBlockEqual>(
					make_unique<BlkXored>(
						make_shared<BlkString>(
							"0000000000000000ffffffffffffffff"
						),
						make_shared<BlkString>(
							"ffffffffffffffff0000000000000000"
						)
					),
					"ffffffffffffffffffffffffffffffff"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkXoredTest::result() const
{
	return tests->result();
}

