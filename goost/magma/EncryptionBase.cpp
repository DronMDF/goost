// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EncryptionBase.h"
#include "Key.h"

using namespace std;
using namespace goost::magma;

EncryptionBase::EncryptionBase(const shared_ptr<const Key> &key)
	: key(key)
{
}

uint64_t EncryptionBase::transform(const uint64_t block) const
{
	uint32_t a = block & 0xffffffff;
	uint32_t b = (block >> 32) & 0xffffffff;

	b ^= key->transform(a, 0);
	a ^= key->transform(b, 1);
	b ^= key->transform(a, 2);
	a ^= key->transform(b, 3);
	b ^= key->transform(a, 4);
	a ^= key->transform(b, 5);
	b ^= key->transform(a, 6);
	a ^= key->transform(b, 7);

	b ^= key->transform(a, 0);
	a ^= key->transform(b, 1);
	b ^= key->transform(a, 2);
	a ^= key->transform(b, 3);
	b ^= key->transform(a, 4);
	a ^= key->transform(b, 5);
	b ^= key->transform(a, 6);
	a ^= key->transform(b, 7);

	b ^= key->transform(a, 0);
	a ^= key->transform(b, 1);
	b ^= key->transform(a, 2);
	a ^= key->transform(b, 3);
	b ^= key->transform(a, 4);
	a ^= key->transform(b, 5);
	b ^= key->transform(a, 6);
	a ^= key->transform(b, 7);

	b ^= key->transform(a, 7);
	a ^= key->transform(b, 6);
	b ^= key->transform(a, 5);
	a ^= key->transform(b, 4);
	b ^= key->transform(a, 3);
	a ^= key->transform(b, 2);
	b ^= key->transform(a, 1);
	a ^= key->transform(b, 0);

	return (uint64_t(a) << 32) | b;
}
