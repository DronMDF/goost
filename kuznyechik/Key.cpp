#include "Key.h"
#include "Block.h"
#include "KeyDataString.h"
#include "KeyIter.h"

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
	const auto t1 = L(S(block ^ k1->value()));
	const auto t2 = L(S(t1 ^ k2->value()));
	const auto t3 = L(S(t2 ^ k3->value()));
	const auto t4 = L(S(t3 ^ k4->value()));
	const auto t5 = L(S(t4 ^ k5->value()));
	const auto t6 = L(S(t5 ^ k6->value()));
	const auto t7 = L(S(t6 ^ k7->value()));
	const auto t8 = L(S(t7 ^ k8->value()));
	const auto t9 = L(S(t8 ^ k9->value()));
	return t9 ^ k10->value();
}
