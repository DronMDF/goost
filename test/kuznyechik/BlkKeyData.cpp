// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkKeyData.h"

using namespace std;
using namespace goost::kuznyechik;
using namespace kuznyechik;

BlkKeyDataHigh::BlkKeyDataHigh(const shared_ptr<const Key::Data> &key)
	: key(key)
{
}

pair<uint64_t, uint64_t> BlkKeyDataHigh::value() const
{
	return key->high()->value();
}

BlkKeyDataLow::BlkKeyDataLow(const shared_ptr<const Key::Data> &key)
	: key(key)
{
}

pair<uint64_t, uint64_t> BlkKeyDataLow::value() const
{
	return key->low()->value();
}
