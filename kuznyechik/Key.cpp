// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Key.h"
#include "BlkL.h"
#include "BlkRaw.h"
#include "BlkS.h"
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

BlkRaw Key::encrypt(const BlkRaw &block) const
{
	// @todo #73:30min Lazy object BlkL and BlkS looks ugly in this context
	//  Maybe i need to introduce LSX object? Or rework parameters passing to them.
	const auto t1 = BlkL(make_unique<BlkS>(block ^ k1->value())).value();
	const auto t2 = BlkL(make_unique<BlkS>(BlkRaw(t1) ^ k2->value())).value();
	const auto t3 = BlkL(make_unique<BlkS>(BlkRaw(t2) ^ k3->value())).value();
	const auto t4 = BlkL(make_unique<BlkS>(BlkRaw(t3) ^ k4->value())).value();
	const auto t5 = BlkL(make_unique<BlkS>(BlkRaw(t4) ^ k5->value())).value();
	const auto t6 = BlkL(make_unique<BlkS>(BlkRaw(t5) ^ k6->value())).value();
	const auto t7 = BlkL(make_unique<BlkS>(BlkRaw(t6) ^ k7->value())).value();
	const auto t8 = BlkL(make_unique<BlkS>(BlkRaw(t7) ^ k8->value())).value();
	const auto t9 = BlkL(make_unique<BlkS>(BlkRaw(t8) ^ k9->value())).value();
	return BlkRaw(t9) ^ k10->value();
}
