// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxByte.h"
#include "SboxByte64Tab.h"

using namespace std;
using namespace magma;

SboxByte::SboxByte(const std::vector<uint8_t> &uz)
	: SboxByte(
		make_unique<SboxByte64Tab>(uz, 0),
		make_unique<SboxByte64Tab>(uz, 1),
		make_unique<SboxByte64Tab>(uz, 2),
		make_unique<SboxByte64Tab>(uz, 3)
	)
{
}

SboxByte::SboxByte(
		unique_ptr<const Tab> tab1,
		unique_ptr<const Tab> tab2,
		unique_ptr<const Tab> tab3,
		unique_ptr<const Tab> tab4
	)
	: tab1(move(tab1)), tab2(move(tab2)), tab3(move(tab3)), tab4(move(tab4))
{
}

uint32_t SboxByte::transform(uint32_t v) const
{
	return tab1->translate(v) |
		(tab2->translate(v >> 8) << 8) |
		(tab3->translate(v >> 16) << 16) |
		(tab4->translate(v >> 24) << 24);
}
