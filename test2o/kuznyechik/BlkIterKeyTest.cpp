// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkIterKeyTest.h"
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <kuznyechik/KeyDataString.h>
#include <kuznyechik/BlkCached.h>
#include <kuznyechik/BlkRaw.h>
#include <kuznyechik/BlkIterKey.h>
#include <kuznyechik/BlkRaw.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

BlkIterKeyTest::BlkIterKeyTest()
	: key_data(
		make_unique<KeyDataString>(
			"8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef"
		)
	  ),
	  k1(make_shared<BlkCached>(key_data->high())),
	  k2(make_shared<BlkCached>(key_data->low())),
	  k3(make_shared<BlkCached>(make_shared<BlkIterKey>(k1, k2, 1, 8))),
	  k4(make_shared<BlkCached>(make_shared<BlkIterKey>(k1, k2, 1, 7))),
	  k5(make_shared<BlkCached>(make_shared<BlkIterKey>(k3, k4, 9, 16))),
	  k6(make_shared<BlkCached>(make_shared<BlkIterKey>(k3, k4, 9, 15))),
	  k7(make_shared<BlkCached>(make_shared<BlkIterKey>(k5, k6, 17, 24))),
	  k8(make_shared<BlkCached>(make_shared<BlkIterKey>(k5, k6, 17, 23))),
	  k9(make_shared<BlkCached>(make_shared<BlkIterKey>(k7, k8, 25, 32))),
	  k10(make_shared<BlkCached>(make_shared<BlkIterKey>(k7, k8, 25, 31))),
	  tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<TestNamed>(
				"R3412_A14_K1",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k1),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x0011223344556677,
							0x8899aabbccddeeff
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K2",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k2),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x0123456789abcdef,
							0xfedcba9876543210
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K3",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k3),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x228d6aef8cc78c44,
							0xdb31485315694343
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K4",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k4),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x15ebadc40a9ffd04,
							0x3d4553d8e9cfec68
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K5",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k5),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0xd3e59246f429f1ac,
							0x57646468c44a5e28
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K6",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k6),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0xb532e82834da581b,
							0xbd079435165c6432
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K7",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k7),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x705727265a0098b1,
							0x51e640757e8745de
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K8",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k8),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0xd72a91a22286f984,
							0x5a7925017b9fdd3e
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K9",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k9),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0xa5f32f73cdb6e517,
							0xbb44e25378c73123
						)
					)
				)
			),
			make_shared<TestNamed>(
				"R3412_A14_K10",
				make_shared<TestEqual>(
					make_unique<ReprBlock>(k10),
					make_unique<ReprBlock>(
						make_unique<BlkRaw>(
							0x755dbaa88e4a4043,
							0x72e9dd7416bcf45b
						)
					)
				)
			)
		)
	)
{
}

unique_ptr<const Result> BlkIterKeyTest::result() const
{
	return tests->result();
}
