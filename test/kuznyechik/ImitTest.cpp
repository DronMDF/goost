
// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ImitTest.h"
#include <2out/TestNamed.h>
#include <2out/TestStartsWith.h>
#include <goost/kuznyechik/Imit.h>
#include <goost/kuznyechik/StMemory.h>
#include <goost/kuznyechik/Key.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

ImitTest::ImitTest()
	: tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"R3413_A162",
				make_shared<TestStartsWith>(
					make_unique<ReprBlock>(
						make_unique<Imit>(
							make_unique<const StMemory>(
								vector<uint64_t>{
									0xffeeddccbbaa9988,
									0x1122334455667700,
									0x8899aabbcceeff0a,
									0x0011223344556677,
									0x99aabbcceeff0a00,
									0x1122334455667788,
									0xaabbcceeff0a0011,
									0x2233445566778899
								}
							),
							make_unique<const Key>(
								"8899aabbccddeeff0011223344556677"
								"fedcba98765432100123456789abcdef"
							)
						)
					),
					"336f4d296059fbe3"
				)
			)
		)
	)
{
}

unique_ptr<const Result> ImitTest::result() const
{
	return tests->result();
}
