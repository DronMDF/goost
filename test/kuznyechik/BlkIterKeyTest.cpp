// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkIterKeyTest.h"
#include <2out/TestNamed.h>
#include <goost/kuznyechik/BlkCached.h>
#include <goost/kuznyechik/BlkIterKey.h>
#include <goost/kuznyechik/KeyDataString.h>
#include "TestBlockEqual.h"

using namespace std;
using namespace oout;
using namespace goost::kuznyechik;
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
				make_shared<TestBlockEqual>(k1, "8899aabbccddeeff0011223344556677")
			),
			make_shared<TestNamed>(
				"R3412_A14_K2",
				make_shared<TestBlockEqual>(k2, "fedcba98765432100123456789abcdef")
			),
			make_shared<TestNamed>(
				"R3412_A14_K3",
				make_shared<TestBlockEqual>(k3, "db31485315694343228d6aef8cc78c44")
			),
			make_shared<TestNamed>(
				"R3412_A14_K4",
				make_shared<TestBlockEqual>(k4, "3d4553d8e9cfec6815ebadc40a9ffd04")
			),
			make_shared<TestNamed>(
				"R3412_A14_K5",
				make_shared<TestBlockEqual>(k5, "57646468c44a5e28d3e59246f429f1ac")
			),
			make_shared<TestNamed>(
				"R3412_A14_K6",
				make_shared<TestBlockEqual>(k6, "bd079435165c6432b532e82834da581b")
			),
			make_shared<TestNamed>(
				"R3412_A14_K7",
				make_shared<TestBlockEqual>(k7, "51e640757e8745de705727265a0098b1")
			),
			make_shared<TestNamed>(
				"R3412_A14_K8",
				make_shared<TestBlockEqual>(k8, "5a7925017b9fdd3ed72a91a22286f984")
			),
			make_shared<TestNamed>(
				"R3412_A14_K9",
				make_shared<TestBlockEqual>(k9, "bb44e25378c73123a5f32f73cdb6e517")
			),
			make_shared<TestNamed>(
				"R3412_A14_K10",
				make_shared<TestBlockEqual>(k10, "72e9dd7416bcf45b755dbaa88e4a4043")
			)
		)
	)
{
}

unique_ptr<const Result> BlkIterKeyTest::result() const
{
	return tests->result();
}
