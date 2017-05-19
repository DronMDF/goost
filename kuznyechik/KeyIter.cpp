// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "KeyIter.h"
#include <cstring>
#include "Block.h"
#include "LBlock.h"
#include "SBlock.h"

using namespace std;
using namespace kuznyechik;

KeyIter1::KeyIter1(const shared_ptr<const Key::Data> &key_data)
	: key_data(key_data)
{
}

Block KeyIter1::value() const
{
	return key_data->high();
}

KeyIter2::KeyIter2(const shared_ptr<const Key::Data> &key_data)
	: key_data(key_data)
{
}

Block KeyIter2::value() const
{
	return key_data->low();
}

KeyIterAny::KeyIterAny(const shared_ptr<const Key::Data> &key_data, int iter)
	: k1(make_unique<KeyIter1>(key_data)), k2(make_unique<KeyIter2>(key_data)), iter(iter)
{
}

Block KeyIterAny::value() const
{
	return generate(k2->value(), k1->value(), 1);
}

Block KeyIterAny::generate(const Block &a, const Block &b, int n) const
{
	if (n > iter) {
		return b;
	}

	// @todo #82:30min Cn is a const key.
	//  Need to predefine this keys
	const auto cn = LBlock(Block(n)).value();
	return generate(b, a ^ LBlock(SBlock(b ^ cn).value()).value(), n + 1);
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
