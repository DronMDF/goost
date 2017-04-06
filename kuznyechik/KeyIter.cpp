#include "KeyIter.h"
#include <cstring>
#include "Block.h"

using namespace std;
using namespace kuznyechik;

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

	const Block a2 = a0 ^ LSX(a1, c1);
	const Block a3 = a1 ^ LSX(a2, c2);
	const Block a4 = a2 ^ LSX(a3, c3);
	const Block a5 = a3 ^ LSX(a4, c4);
	const Block a6 = a4 ^ LSX(a5, c5);
	const Block a7 = a5 ^ LSX(a6, c6);
	const Block a8 = a6 ^ LSX(a7, c7);
	const Block a9 = a7 ^ LSX(a8, c8);

	return a9;
}

Block KeyIter3::R(const Block &a) const
{
	constexpr int k[16] = {
		1, 148, 32, 133, 16, 194, 192, 1, 251, 1, 192, 194, 16, 133, 32, 148
	};
	array<uint8_t, 17> data;
	memcpy(&data[0], &a.low, sizeof(a.low));
	memcpy(&data[8], &a.high, sizeof(a.high));
	int sum = 0;
	for (int i = 0; i < 16; i++) {
		sum ^= data[i] * k[i];
	}
	data[16] = sum;
	return Block(&data[1]);
}

Block KeyIter3::L(const Block &a) const
{
	const auto t1 = R(a);
	const auto t2 = R(t1);
	const auto t3 = R(t2);
	const auto t4 = R(t3);
	const auto t5 = R(t4);
	const auto t6 = R(t5);
	const auto t7 = R(t6);
	const auto t8 = R(t7);
	const auto t9 = R(t8);
	const auto t10 = R(t9);
	const auto t11 = R(t10);
	const auto t12 = R(t11);
	const auto t13 = R(t12);
	const auto t14 = R(t13);
	const auto t15 = R(t14);
	const auto t16 = R(t15);
	return t16;
}

Block KeyIter3::LSX(const Block &a, const Block &c [[gnu::unused]]) const
{
	return a;
}
