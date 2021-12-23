// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataStringTest.h"
#include <2out/2out.h>
#include <goost/magma/KeyDataString.h>
#include "ReprKeyData.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

KeyDataStringTest::KeyDataStringTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"string key",
				make_shared<MatchTest>(
					make_shared<ReprKeyData>(
						make_shared<KeyDataString>(
							"ffeeddccbbaa99887766554433221100"
							"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
						)
					),
					// In TK26 key represent as big number,
					// where high part is K0. Our representation -
					// is a byte string in host order from K0 to K7
					"ccddeeff8899aabb4455667700112233"
					"f3f2f1f0f7f6f5f4fbfaf9f8fffefdfc"s
				)
			)
		)
	)
{
}

unique_ptr<const Result> KeyDataStringTest::result() const
{
	return tests->result();
}
