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
