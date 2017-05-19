// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ImitedBlock.h"

using namespace std;
using namespace gost89;
using namespace magma;

ImitedBlock::ImitedBlock(const Block &block, const shared_ptr<const Key> &key)
	: block(block), key(key)
{
}

Block ImitedBlock::value() const
{
	return key->forward(key->forward(block));
}
