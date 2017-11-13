// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyCachedDataTest.h"
#include <random>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <magma/KeyCachedData.h>
#include "ReprKeyData.h"

using namespace std;
using namespace oout;
using namespace magma;

class KeyDataRandom final : public KeyData {
public:
	KeyDataRandom()
		: engine(make_shared<default_random_engine>())
	{
	}

	uint32_t key(int) const override
	{
		return (*engine)();
	}
private:
	const shared_ptr<default_random_engine> engine;
};

KeyCachedDataTest::KeyCachedDataTest()
	: key_data(
		make_shared<KeyCachedData>(
			make_unique<KeyDataRandom>()
		)
	  ),
	  tests(
		make_unique<TestNamed>(
			__func__,
			make_shared<const TestNamed>(
				"Cached first result",
				make_shared<TestEqual>(
					make_shared<ReprKeyData>(key_data),
					make_shared<ReprKeyData>(key_data)
				)
			)
		)
	)
{
}

unique_ptr<const Result> KeyCachedDataTest::result() const
{
	return tests->result();
}

