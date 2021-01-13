// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkXored.h"

using namespace std;
using namespace goost::kuznyechik;

BlkXored::BlkXored(const shared_ptr<const Block> &a, const shared_ptr<const Block> &b)
	: a(a), b(b)
{
}

pair<uint64_t, uint64_t> BlkXored::value() const
{
	const auto a_value = a->value();
	const auto b_value = b->value();
	return {a_value.first ^ b_value.first, a_value.second ^ b_value.second};
}

