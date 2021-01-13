// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Key.h"
#include "BlkCached.h"
#include "BlkIterKey.h"
#include "BlkL.h"
#include "BlkRaw.h"
#include "BlkS.h"
#include "BlkXored.h"
#include "KeyDataString.h"

using namespace std;
using namespace goost::kuznyechik;

Key::Key(const string &key_data)
	: Key(make_shared<KeyDataString>(key_data))
{
}

Key::Key(const std::shared_ptr<const Data> &key_data)
	: k1(make_shared<BlkCached>(key_data->high())),
	  k2(make_shared<BlkCached>(key_data->low())),
	  k3(make_shared<BlkCached>(make_shared<BlkIterKey>(k1, k2, 1, 8))),
	  k4(make_shared<BlkCached>(make_shared<BlkIterKey>(k1, k2, 1, 7))),
	  k5(make_shared<BlkCached>(make_shared<BlkIterKey>(k3, k4, 9, 16))),
	  k6(make_shared<BlkCached>(make_shared<BlkIterKey>(k3, k4, 9, 15))),
	  k7(make_shared<BlkCached>(make_shared<BlkIterKey>(k5, k6, 17, 24))),
	  k8(make_shared<BlkCached>(make_shared<BlkIterKey>(k5, k6, 17, 23))),
	  k9(make_shared<BlkCached>(make_shared<BlkIterKey>(k7, k8, 25, 32))),
	  k10(make_shared<BlkCached>(make_shared<BlkIterKey>(k7, k8, 25, 31)))
{
}

unique_ptr<const Block> Key::encrypt(const shared_ptr<const Block> &block) const
{
	const auto t1 = encryptStep(block, k1);
	const auto t2 = encryptStep(t1, k2);
	const auto t3 = encryptStep(t2, k3);
	const auto t4 = encryptStep(t3, k4);
	const auto t5 = encryptStep(t4, k5);
	const auto t6 = encryptStep(t5, k6);
	const auto t7 = encryptStep(t6, k7);
	const auto t8 = encryptStep(t7, k8);
	const auto t9 = encryptStep(t8, k9);
	return make_unique<BlkXored>(t9, k10);
}

shared_ptr<const Block> Key::encryptStep(
		const shared_ptr<const Block> &block,
		const shared_ptr<const Block> &kn
	) const
{
	return make_unique<BlkL>(make_unique<BlkS>(make_unique<BlkXored>(block, kn)));
}
