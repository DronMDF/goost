// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyDataNativeTest.h"
#include <2out/2out.h>
#include <goost/magma/KeyDataNative.h>
#include "ReprKeyData.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
using namespace magma;

KeyDataNativeTest::KeyDataNativeTest()
	: tests(
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"Native key",
				make_shared<MatchTest>(
					make_shared<ReprKeyData>(
						make_shared<KeyDataNative>(
							vector<uint32_t>{
								0xE0F67504U,
								0xFAFB3850U,
								0x90C3C7D2U,
								0x3DCAB3EDU,
								0x42124715U,
								0x8A1EAE91U,
								0x9ECD792FU,
								0xBDEFBCD2U
							}
						)
					),
					"0475f6e05038fbfad2c7c390edb3ca3d"
					"1547124291ae1e8a2f79cd9ed2bcefbd"
				)
			)
		)
	)
{
}

unique_ptr<const Result> KeyDataNativeTest::result() const
{
	return tests->result();
}
