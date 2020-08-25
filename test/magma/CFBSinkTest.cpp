// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CFBSinkTest.h"
#include <goost/magma/CFBSink.h>
#include <goost/magma/Key.h>
#include <test/TestSink.h>
#include <test/HexMatch.h>

using namespace std;
using namespace oout;
using namespace magma;

class CFBSinkText final : public oout::Text {
public:
	CFBSinkText(
		const shared_ptr<const Key> &key,
		const string &iv,
		const string &data
	) : key(key), iv(iv), data(data)
	{
	}

	string asString() const override
	{
		const auto out = CFBSink(
			make_shared<TestSink>()
			/*, key, iv*/
		).write(to_bytes(data))->finalize();
		return dynamic_pointer_cast<const TestSink>(out)->asHexString();
	}

private:
	vector<byte> to_bytes(const string &str) const
	{
		vector<byte> rv;
		for (size_t i = 0; i < str.size(); i += 2) {
			byte b = static_cast<byte>(stoul(str.substr(i, 2), 0, 16));
			rv.push_back(b);
		}
		return rv;
	}

	const shared_ptr<const Key> key;
	const string iv;
	const string data;
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
			"1234567890abcdef234567890abcdef1",
			"92def06b3c130a59"
			"db54c704f8189d20"
			"4a98fb2e67a8024c"
			"8912409b17b57e41"
		),
		make_shared<HexMatch>(
			"db37e0e266903c83"
			"0d46644c1f9a089c"
			"24bdd2035315d38b"
			"bcc0321421075505"
		)
	)
)
{
}
