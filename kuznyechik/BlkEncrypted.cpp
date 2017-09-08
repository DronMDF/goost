// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncrypted.h"
#include "Key.h"

using namespace std;
using namespace kuznyechik;

BlkEncrypted::BlkEncrypted(const BlkRaw &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

pair<uint64_t, uint64_t> BlkEncrypted::value() const
{
	const auto v = key->encrypt(block);
	return {v.low, v.high};
}

