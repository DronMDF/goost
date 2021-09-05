// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncryptedTest.h"
#include <2out/NamedTest.h>
#include <goost/kuznyechik/BlkEncrypted.h>
#include <goost/kuznyechik/BlkString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkEncryptedTest::BlkEncryptedTest()
	: key(make_unique<Key>("8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef")),
	  tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<NamedTest>(
				"R3412_A15, R3412_A11_1",
				make_shared<TestBlockEqual>(
					make_unique<BlkEncrypted>(
						make_shared<BlkString>(
							"1122334455667700ffeeddccbbaa9988"
						),
						key
					),
					"7f679d90bebc24305a468d42b9d4edcd"
				)
			),
			make_shared<NamedTest>(
				"R3412_A11_2",
				make_shared<TestBlockEqual>(
					make_unique<BlkEncrypted>(
						make_shared<BlkString>(
							"00112233445566778899aabbcceeff0a"
						),
						key
					),
					"b429912c6e0032f9285452d76718d08b"
				)
			),
			make_shared<NamedTest>(
				"R3412_A11_3",
				make_shared<TestBlockEqual>(
					make_unique<BlkEncrypted>(
						make_shared<BlkString>(
							"112233445566778899aabbcceeff0a00"
						),
						key
					),
					"f0ca33549d247ceef3f5a5313bd4b157"
				)
			),
			make_shared<NamedTest>(
				"R3412_A11_4",
				make_shared<TestBlockEqual>(
					make_unique<BlkEncrypted>(
						make_shared<BlkString>(
							"2233445566778899aabbcceeff0a0011"
						),
						key
					),
					"d0b09ccde830b9eb3a02c4c5aa8ada98"
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkEncryptedTest::result() const
{
	return tests->result();
}
