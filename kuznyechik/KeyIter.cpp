// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyIter.h"
#include <cstring>
#include "BlkL.h"
#include "BlkRaw.h"
#include "BlkS.h"
#include "BlkXored.h"

using namespace std;
using namespace kuznyechik;

KeyIter1::KeyIter1(const shared_ptr<const Key::Data> &key_data)
	: key_data(key_data)
{
}

BlkRaw KeyIter1::value() const
{
	return key_data->high();
}

KeyIter2::KeyIter2(const shared_ptr<const Key::Data> &key_data)
	: key_data(key_data)
{
}

BlkRaw KeyIter2::value() const
{
	return key_data->low();
}

KeyIterAny::KeyIterAny(const shared_ptr<const Key::Data> &key_data, int iter)
	: k1(make_unique<KeyIter1>(key_data)), k2(make_unique<KeyIter2>(key_data)), iter(iter)
{
}

BlkRaw KeyIterAny::value() const
{
	return BlkRaw(
		generate(make_shared<BlkRaw>(k2->value()), make_shared<BlkRaw>(k1->value()), 1)
	);
}

shared_ptr<const Block> KeyIterAny::generate(
	const shared_ptr<const Block> &a,
	const shared_ptr<const Block> &b,
	int n
) const
{
	if (n > iter) {
		return b;
	}

	// @todo #82:30min Cn is a const key.
	//  Need to predefine this keys
	const auto cn = make_shared<BlkL>(make_unique<BlkRaw>(n));
	return generate(
		b,
		make_shared<BlkXored>(
			// @todo #235 Recurse take long time.
			//  Need introduce BlkCached, for keep intermediate values and break
			//  resucrivity
			make_shared<BlkRaw>(a),
			make_unique<BlkL>(make_unique<BlkS>(make_unique<BlkXored>(b, cn)))
		),
		n + 1
	);
}

KeyIter3::KeyIter3(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 8)
{
}

KeyIter4::KeyIter4(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 7)
{
}

KeyIter5::KeyIter5(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 16)
{
}

KeyIter6::KeyIter6(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 15)
{
}

KeyIter7::KeyIter7(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 24)
{
}

KeyIter8::KeyIter8(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 23)
{
}

KeyIter9::KeyIter9(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 32)
{
}

KeyIter10::KeyIter10(const shared_ptr<const Key::Data> &key_data)
	: KeyIterAny(key_data, 31)
{
}
