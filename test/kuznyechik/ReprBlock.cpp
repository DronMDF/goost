// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprBlock.h"
#include <iomanip>
#include <sstream>
#include <goost/kuznyechik/Block.h>

using namespace std;
using namespace kuznyechik;

ReprBlock::ReprBlock(const std::shared_ptr<const Block> &block)
	: block(block)
{
}

string ReprBlock::asString() const
{
	const auto value = block->value();
	ostringstream os;
	os << hex << setfill('0') << setw(16) << value.second << setw(16) << value.first << dec;
	return os.str();
}
