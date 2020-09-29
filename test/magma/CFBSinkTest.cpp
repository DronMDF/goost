// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSinkTest.h"
#include <limits>
#include <goost/Source.h>
#include <goost/magma/CFBSink.h>
#include <goost/magma/Key.h>
#include <test/TestSink.h>
#include <test/Hex64Source.h>
#include <test/SourceMatch.h>

using namespace std;
using namespace oout;
using namespace goost;
using namespace goost::magma;

class CFBSinkText final : public oout::Text {
public:
	CFBSinkText(
		const shared_ptr<const Key> &key,
		const uint64_t ivl,
		const uint64_t ivr,
		const shared_ptr<const Source> &data
	) : key(key), ivl(ivl), ivr(ivr), data(data)
	{
	}

	string asString() const override
	{
		const auto bytes = data->read(numeric_limits<size_t>::max());
		const auto out = CFBSink(
			make_shared<TestSink>(),
			key,
			ivl,
			ivr
		).write(bytes.first)->finalize();
		return dynamic_pointer_cast<const TestSink>(out)->asHexString();
	}

private:
	const shared_ptr<const Key> key;
	const uint64_t ivl;
	const uint64_t ivr;
	const shared_ptr<const Source> data;
};

CFBSinkTest::CFBSinkTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Cipher feedback encryption by GOST-34.13 example",
		make_shared<CFBSinkText>(
			make_shared<Key>(
				"ffeeddccbbaa99887766554433221100"
				"f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
			),
			0x1234567890abcdef,
			0x234567890abcdef1,
			make_shared<Hex64Source>(
				"92def06b3c130a59"
				"db54c704f8189d20"
				"4a98fb2e67a8024c"
				"8912409b17b57e41"
			)
		),
		make_shared<SourceMatch>(
			make_shared<Hex64Source>(
				"db37e0e266903c83"
				"0d46644c1f9a089c"
				"24bdd2035315d38b"
				"bcc0321421075505"
			)
		)
	)
)
{
}
