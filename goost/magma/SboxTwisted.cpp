// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxTwisted.h"

using namespace std;
using namespace goost::magma;

SboxTwisted::SboxTwisted(unique_ptr<const Sbox> sbox)
	: sbox(move(sbox))
{
}

uint32_t SboxTwisted::transform(uint32_t value) const
{
	const auto tmp = sbox->transform(value);
	return (tmp << 11) | ((tmp >> 21) & 0x7ff);
}
