// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Key.h"
#include "BlkL.h"
#include "BlkRaw.h"
#include "BlkS.h"
#include "BlkXored.h"
#include "KeyDataString.h"
#include "KeyIter.h"

using namespace std;
using namespace kuznyechik;

Key::Key(const string &key_data)
	: Key(make_shared<KeyDataString>(key_data))
{
}

Key::Key(const std::shared_ptr<const Data> &key_data)
	: k1(make_unique<KeyIter1>(key_data)),
	  k2(make_unique<KeyIter2>(key_data)),
	  k3(make_unique<KeyIter3>(key_data)),
	  k4(make_unique<KeyIter4>(key_data)),
	  k5(make_unique<KeyIter5>(key_data)),
	  k6(make_unique<KeyIter6>(key_data)),
	  k7(make_unique<KeyIter7>(key_data)),
	  k8(make_unique<KeyIter8>(key_data)),
	  k9(make_unique<KeyIter9>(key_data)),
	  k10(make_unique<KeyIter10>(key_data))
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
