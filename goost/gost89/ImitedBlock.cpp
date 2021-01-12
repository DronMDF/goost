// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ImitedBlock.h"
#include <goost/magma/BlkForwarded.h>

using namespace std;
using namespace goost::gost89;
using namespace goost::magma;

ImitedBlock::ImitedBlock(const BlkRaw &block, const shared_ptr<const LazyKey> &key)
	: block(block), key(key)
{
}

BlkRaw ImitedBlock::value() const
{
	return BlkRaw(
		make_shared<BlkForwarded>(
			make_shared<BlkForwarded>(
				make_shared<BlkRaw>(block.value()),
				key
			),
			key
		)
	);
}
