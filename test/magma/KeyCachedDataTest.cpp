// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyCachedDataTest.h"
#include <random>
#include <2out/EqualMatch.h>
#include <2out/MatchTest.h>
#include <2out/NamedTest.h>
#include <goost/magma/KeyCachedData.h>
#include "ReprKeyData.h"

using namespace std;
using namespace oout;
using namespace goost::magma;
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
		make_unique<NamedTest>(
			__func__,
			make_shared<const NamedTest>(
				"Cached first result",
				make_shared<MatchTest>(
					make_shared<ReprKeyData>(key_data),
					make_shared<EqualMatch>(ReprKeyData(key_data).asString())
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

