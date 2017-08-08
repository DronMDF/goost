#include "ReprKey.h"
#include <2out/ReprPrintable.h>
#include <kuznyechik/Block.h>

using namespace std;
using namespace oout;
using namespace kuznyechik;

ReprKeyHigh::ReprKeyHigh(const shared_ptr<Key::Data> &key)
	: key(key)
{
}

string ReprKeyHigh::asString() const
{
	return ReprPrintable<Block>(key->high()).asString();
}

ReprKeyLow::ReprKeyLow(const shared_ptr<Key::Data> &key)
	: key(key)
{
}

string ReprKeyLow::asString() const
{
	return ReprPrintable<Block>(key->low()).asString();
}
