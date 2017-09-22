// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncrypted.h"
#include "BlkRaw.h"
#include "Key.h"

using namespace std;
using namespace kuznyechik;

BlkEncrypted::BlkEncrypted(const shared_ptr<const Block> &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

pair<uint64_t, uint64_t> BlkEncrypted::value() const
{
	return key->encrypt(block)->value();
}
