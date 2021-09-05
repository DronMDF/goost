// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkLTest.h"
#include <2out/NamedTest.h>
#include <goost/kuznyechik/BlkL.h>
#include <goost/kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkLTest::BlkLTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<NamedTest>(
				"R3412_A13_1",
				make_shared<TestBlockEqual>(
					make_unique<BlkL>(
						make_shared<BlkString>(
							"64a59400000000000000000000000000"
						)
					),
					"d456584dd0e3e84cc3166e4b7fa2890d"
				)
			),
			make_shared<NamedTest>(
				"R3412_A13_2",
				make_shared<TestBlockEqual>(
					make_unique<BlkL>(
						make_shared<BlkString>(
							"d456584dd0e3e84cc3166e4b7fa2890d"
						)
					),
					"79d26221b87b584cd42fbc4ffea5de9a"
				)
			),
			make_shared<NamedTest>(
				"R3412_A13_3",
				make_shared<TestBlockEqual>(
					make_unique<BlkL>(
						make_shared<BlkString>(
							"79d26221b87b584cd42fbc4ffea5de9a"
						)
					),
					"0e93691a0cfc60408b7b68f66b513c13"
				)
			),
			make_shared<NamedTest>(
				"R3412_A13_4",
				make_shared<TestBlockEqual>(
					make_unique<BlkL>(
						make_shared<BlkString>(
							"0e93691a0cfc60408b7b68f66b513c13"
						)
					),
					"e6a8094fee0aa204fd97bcb0b44b8580"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkLTest::result() const
{
	return tests->result();
}
