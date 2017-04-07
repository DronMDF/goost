#include "KeyIter.h"
#include <cstring>
#include "Block.h"
#include "RBlock.h"

using namespace std;
using namespace kuznyechik;

Block KeyIterPrimitives::L(const Block &a) const
{
	const auto t1 = RBlock(a).value();
	const auto t2 = RBlock(t1).value();
	const auto t3 = RBlock(t2).value();
	const auto t4 = RBlock(t3).value();
	const auto t5 = RBlock(t4).value();
	const auto t6 = RBlock(t5).value();
	const auto t7 = RBlock(t6).value();
	const auto t8 = RBlock(t7).value();
	const auto t9 = RBlock(t8).value();
	const auto t10 = RBlock(t9).value();
	const auto t11 = RBlock(t10).value();
	const auto t12 = RBlock(t11).value();
	const auto t13 = RBlock(t12).value();
	const auto t14 = RBlock(t13).value();
	const auto t15 = RBlock(t14).value();
	const auto t16 = RBlock(t15).value();
	return t16;
}

Block KeyIterPrimitives::S(const Block &a) const
{
	array<uint8_t, 256> sbox = {{
		252, 238, 221, 17, 207, 110, 49, 22, 251, 196, 250, 218, 35, 197, 4, 77, 233,
		119, 240, 219, 147, 46, 153, 186, 23, 54, 241, 187, 20, 205, 95, 193, 249, 24, 101,
		90, 226, 92, 239, 33, 129, 28, 60, 66, 139, 1, 142, 79, 5, 132, 2, 174, 227, 106,
		143, 160, 6, 11, 237, 152, 127, 212, 211, 31, 235, 52, 44, 81, 234, 200, 72, 171,
		242, 42, 104, 162, 253, 58, 206, 204, 181, 112, 14, 86, 8, 12, 118, 18, 191, 114,
		19, 71, 156, 183, 93, 135, 21, 161, 150, 41, 16, 123, 154, 199, 243, 145, 120, 111,
		157, 158, 178, 177, 50, 117, 25, 61, 255, 53, 138, 126, 109, 84, 198, 128, 195, 189,
		13, 87, 223, 245, 36, 169, 62, 168, 67, 201, 215, 121, 214, 246, 124, 34, 185, 3,
		224, 15, 236, 222, 122, 148, 176, 188, 220, 232, 40, 80, 78, 51, 10, 74, 167, 151,
		96, 115, 30, 0, 98, 68, 26, 184, 56, 130, 100, 159, 38, 65, 173, 69, 70, 146, 39,
		94, 85, 47, 140, 163, 165, 125, 105, 213, 149, 59, 7, 88, 179, 64, 134, 172, 29,
		247, 48, 55, 107, 228, 136, 217, 231, 137, 225, 27, 131, 73, 76, 63, 248, 254, 141,
		83, 170, 144, 202, 216, 133, 97, 32, 113, 103, 164, 45, 43, 9, 91, 203, 155, 37,
		208, 190, 229, 108, 82, 89, 166, 116, 210, 230, 244, 180, 192, 209, 102, 175, 194,
		57, 75, 99, 182
	}};

	array<uint8_t, 16> data;
	memcpy(&data[0], &a.low, sizeof(a.low));
	memcpy(&data[8], &a.high, sizeof(a.high));
	for (int i = 0; i < 16; i++) {
		data[i] = sbox[data[i]];
	}
	return Block(&data[0]);
}

KeyIter1::KeyIter1(const shared_ptr<const Key::Data> &key_data)
	: key_data(key_data)
{
}

Block KeyIter1::value() const
{
	return key_data->high();
}

KeyIter2::KeyIter2(const shared_ptr<const Key::Data> &key_data)
	: key_data(key_data)
{
}

Block KeyIter2::value() const
{
	return key_data->low();
}

KeyIter3::KeyIter3(const shared_ptr<const Key::Data> &key_data)
	: k1(make_unique<KeyIter1>(key_data)), k2(make_unique<KeyIter2>(key_data))
{
}

Block KeyIter3::value() const
{
	auto a1 = k1->value();
	auto a0 = k2->value();

	const Block c1 = L(Block(1));
	const Block c2 = L(Block(2));
	const Block c3 = L(Block(3));
	const Block c4 = L(Block(4));
	const Block c5 = L(Block(5));
	const Block c6 = L(Block(6));
	const Block c7 = L(Block(7));
	const Block c8 = L(Block(8));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));
	const Block a9 = a7 ^ L(S(a8 ^ c8));

	return a9;
}

KeyIter4::KeyIter4(const shared_ptr<const Key::Data> &key_data)
	: k1(make_unique<KeyIter1>(key_data)), k2(make_unique<KeyIter2>(key_data))
{
}

Block KeyIter4::value() const
{
	auto a1 = k1->value();
	auto a0 = k2->value();

	const Block c1 = L(Block(1));
	const Block c2 = L(Block(2));
	const Block c3 = L(Block(3));
	const Block c4 = L(Block(4));
	const Block c5 = L(Block(5));
	const Block c6 = L(Block(6));
	const Block c7 = L(Block(7));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));

	return a8;
}

KeyIter5::KeyIter5(const shared_ptr<const Key::Data> &key_data)
	: k3(make_unique<KeyIter3>(key_data)), k4(make_unique<KeyIter4>(key_data))
{
}

Block KeyIter5::value() const
{
	auto a1 = k3->value();
	auto a0 = k4->value();

	const Block c1 = L(Block(9));
	const Block c2 = L(Block(10));
	const Block c3 = L(Block(11));
	const Block c4 = L(Block(12));
	const Block c5 = L(Block(13));
	const Block c6 = L(Block(14));
	const Block c7 = L(Block(15));
	const Block c8 = L(Block(16));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));
	const Block a9 = a7 ^ L(S(a8 ^ c8));

	return a9;
}

KeyIter6::KeyIter6(const shared_ptr<const Key::Data> &key_data)
	: k3(make_unique<KeyIter3>(key_data)), k4(make_unique<KeyIter4>(key_data))
{
}

Block KeyIter6::value() const
{
	auto a1 = k3->value();
	auto a0 = k4->value();

	const Block c1 = L(Block(9));
	const Block c2 = L(Block(10));
	const Block c3 = L(Block(11));
	const Block c4 = L(Block(12));
	const Block c5 = L(Block(13));
	const Block c6 = L(Block(14));
	const Block c7 = L(Block(15));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));

	return a8;
}

KeyIter7::KeyIter7(const shared_ptr<const Key::Data> &key_data)
	: k5(make_unique<KeyIter5>(key_data)), k6(make_unique<KeyIter6>(key_data))
{
}

Block KeyIter7::value() const
{
	auto a1 = k5->value();
	auto a0 = k6->value();

	const Block c1 = L(Block(17));
	const Block c2 = L(Block(18));
	const Block c3 = L(Block(19));
	const Block c4 = L(Block(20));
	const Block c5 = L(Block(21));
	const Block c6 = L(Block(22));
	const Block c7 = L(Block(23));
	const Block c8 = L(Block(24));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));
	const Block a9 = a7 ^ L(S(a8 ^ c8));

	return a9;
}

KeyIter8::KeyIter8(const shared_ptr<const Key::Data> &key_data)
	: k5(make_unique<KeyIter5>(key_data)), k6(make_unique<KeyIter6>(key_data))
{
}

Block KeyIter8::value() const
{
	auto a1 = k5->value();
	auto a0 = k6->value();

	const Block c1 = L(Block(17));
	const Block c2 = L(Block(18));
	const Block c3 = L(Block(19));
	const Block c4 = L(Block(20));
	const Block c5 = L(Block(21));
	const Block c6 = L(Block(22));
	const Block c7 = L(Block(23));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));

	return a8;
}

KeyIter9::KeyIter9(const shared_ptr<const Key::Data> &key_data)
	: k7(make_unique<KeyIter7>(key_data)), k8(make_unique<KeyIter8>(key_data))
{
}

Block KeyIter9::value() const
{
	auto a1 = k7->value();
	auto a0 = k8->value();

	const Block c1 = L(Block(25));
	const Block c2 = L(Block(26));
	const Block c3 = L(Block(27));
	const Block c4 = L(Block(28));
	const Block c5 = L(Block(29));
	const Block c6 = L(Block(30));
	const Block c7 = L(Block(31));
	const Block c8 = L(Block(32));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));
	const Block a9 = a7 ^ L(S(a8 ^ c8));

	return a9;
}

KeyIter10::KeyIter10(const shared_ptr<const Key::Data> &key_data)
	: k7(make_unique<KeyIter7>(key_data)), k8(make_unique<KeyIter8>(key_data))
{
}

Block KeyIter10::value() const
{
	auto a1 = k7->value();
	auto a0 = k8->value();

	const Block c1 = L(Block(25));
	const Block c2 = L(Block(26));
	const Block c3 = L(Block(27));
	const Block c4 = L(Block(28));
	const Block c5 = L(Block(29));
	const Block c6 = L(Block(30));
	const Block c7 = L(Block(31));

	const Block a2 = a0 ^ L(S(a1 ^ c1));
	const Block a3 = a1 ^ L(S(a2 ^ c2));
	const Block a4 = a2 ^ L(S(a3 ^ c3));
	const Block a5 = a3 ^ L(S(a4 ^ c4));
	const Block a6 = a4 ^ L(S(a5 ^ c5));
	const Block a7 = a5 ^ L(S(a6 ^ c6));
	const Block a8 = a6 ^ L(S(a7 ^ c7));

	return a8;
}
