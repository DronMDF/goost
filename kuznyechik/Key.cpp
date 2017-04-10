#include "Key.h"
#include "Block.h"
#include "KeyDataString.h"
#include "KeyIter.h"
#include "LBlock.h"
#include "SBlock.h"

using namespace std;
using namespace kuznyechik;

Key::Key(const string &key_data)
	: Key(make_shared<KeyDataString>(key_data))
{
}

Key::Key(const std::shared_ptr<const Data> &key_data)
	: k1(make_unique<KeyIter1>(key_data)),
	  k2(make_unique<KeyIter2>(key_data)),
	  k3(make_unique<KeyIter3>(key_data)),
	  k4(make_unique<KeyIter4>(key_data)),
	  k5(make_unique<KeyIter5>(key_data)),
	  k6(make_unique<KeyIter6>(key_data)),
	  k7(make_unique<KeyIter7>(key_data)),
	  k8(make_unique<KeyIter8>(key_data)),
	  k9(make_unique<KeyIter9>(key_data)),
	  k10(make_unique<KeyIter10>(key_data))
{
}

Block Key::encrypt(const Block &block) const
{
	// @todo #73:30min Lazy object LBlock and SBlock looks ugly in this context
	//  Maybe i need to introduce LSX object? Or rework parameters passing to them.
	const auto t1 = LBlock(SBlock(block ^ k1->value()).value()).value();
	const auto t2 = LBlock(SBlock(t1 ^ k2->value()).value()).value();
	const auto t3 = LBlock(SBlock(t2 ^ k3->value()).value()).value();
	const auto t4 = LBlock(SBlock(t3 ^ k4->value()).value()).value();
	const auto t5 = LBlock(SBlock(t4 ^ k5->value()).value()).value();
	const auto t6 = LBlock(SBlock(t5 ^ k6->value()).value()).value();
	const auto t7 = LBlock(SBlock(t6 ^ k7->value()).value()).value();
	const auto t8 = LBlock(SBlock(t7 ^ k8->value()).value()).value();
	const auto t9 = LBlock(SBlock(t8 ^ k9->value()).value()).value();
	return t9 ^ k10->value();
}
