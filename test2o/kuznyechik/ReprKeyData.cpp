// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprKeyData.h"
#include <kuznyechik/BlkRaw.h>
#include "ReprBlock.h"

using namespace std;
using namespace oout;
using namespace kuznyechik;

ReprKeyDataHigh::ReprKeyDataHigh(const shared_ptr<Key::Data> &key)
	: key(key)
{
}

string ReprKeyDataHigh::asString() const
{
	return ReprBlock(make_unique<BlkRaw>(key->high())).asString();
}

ReprKeyDataLow::ReprKeyDataLow(const shared_ptr<Key::Data> &key)
	: key(key)
{
}

string ReprKeyDataLow::asString() const
{
	return ReprBlock(make_unique<BlkRaw>(key->low())).asString();
}
