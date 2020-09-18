// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <upp11.h>
#include <gost89/DataImit.h>
#include <magma/KeyDataNative.h>
#include <magma/Key.h>
#include <magma/SboxByte.h>
#include <magma/SboxTwisted.h>

using namespace std;
using namespace goost::gost89;
using namespace goost::magma;

UP_SUITE_BEGIN(gost89)
UP_SUITE_BEGIN(DataImitTest)

#define LINE(X) \
0x##X##4##X##5##X##6##X##7, \
0x##X##0##X##1##X##2##X##3, \
0x##X##C##X##D##X##E##X##F, \
0x##X##8##X##9##X##A##X##B

static const uint32_t Text02[] = {
	LINE(0),
	LINE(1),
	LINE(2),
	LINE(3),
	LINE(4),
	LINE(5),
	LINE(6),
	LINE(7),
	LINE(8),
	LINE(9),
	LINE(A),
	LINE(B),
	LINE(C),
	LINE(D),
	LINE(E),
	LINE(F)
};

struct DataImitFixture {
	virtual ~DataImitFixture() = default;

	const shared_ptr<const Sbox> sbox = make_shared<SboxTwisted>(
		make_unique<const SboxByte>(vector<uint8_t>{
			0xc4, 0xed, 0x83, 0xc9, 0x92, 0x98, 0xfe, 0x6b,
			0xff, 0xbe, 0x65, 0x5c, 0xe5, 0x2c, 0xb9, 0x20,
			0x89, 0x57, 0x16, 0xb3, 0x11, 0xf3, 0x98, 0x06,
			0x30, 0x79, 0xc0, 0x97, 0xa8, 0x1a, 0x5d, 0xd5,
			0x2e, 0x01, 0xda, 0x34, 0x73, 0xd5, 0x3b, 0xe8,
			0x4b, 0xc2, 0x77, 0x7e, 0xdc, 0x64, 0xac, 0xaf,
			0x6d, 0xa6, 0x02, 0xf1, 0x07, 0x4f, 0xe1, 0x4a,
			0xba, 0x30, 0x2f, 0x12, 0x56, 0x8b, 0x44, 0x8d
		})
	);
	const shared_ptr<const Key> key = make_shared<const Key>(
		make_unique<const KeyDataNative>(
			vector<uint32_t>{
				0xE0F67504U,
				0xFAFB3850U,
				0x90C3C7D2U,
				0x3DCAB3EDU,
				0x42124715U,
				0x8A1EAE91U,
				0x9ECD792FU,
				0xBDEFBCD2U
			}
		),
		sbox
	);
};

UP_FIXTURE_TEST(SimpleImit, DataImitFixture)
{
	// Given
	vector<uint8_t> data(sizeof(Text02));
	memcpy(&data[0], Text02, data.size());
	const DataImit imit(data, key);
	// Then
	UP_ASSERT_EQUAL(imit.asUInt32(), 0x46738F54);
}

UP_FIXTURE_TEST(Benchmark10M, DataImitFixture)
{
	// Given
	const DataImit imit(vector<uint8_t>(10000000U, 'A'), key);
	// Then
	UP_ASSERT_EQUAL(imit.asUInt32(), 2954209623);
}

UP_SUITE_END()
UP_SUITE_END()
