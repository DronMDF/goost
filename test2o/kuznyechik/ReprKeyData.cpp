// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprKeyData.h"
#include <2out/ReprPrintable.h>
#include <kuznyechik/Block.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

ReprKeyDataHigh::ReprKeyDataHigh(const shared_ptr<Key::Data> &key)
	: key(key)
{
}

string ReprKeyDataHigh::asString() const
{
	return ReprPrintable<Block>(key->high()).asString();
}

ReprKeyDataLow::ReprKeyDataLow(const shared_ptr<Key::Data> &key)
	: key(key)
{
}

string ReprKeyDataLow::asString() const
{
	return ReprPrintable<Block>(key->low()).asString();
}