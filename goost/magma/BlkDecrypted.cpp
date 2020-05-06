// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkDecrypted.h"
#include "BlkBackwarded.h"
#include "BlkForwarded.h"
#include "BlkSwapped.h"

using namespace std;
using namespace magma;

BlkDecrypted::BlkDecrypted(const shared_ptr<const Block> &block, const shared_ptr<const Key> &key)
	: block(
		make_shared<BlkSwapped>(
			make_shared<BlkBackwarded>(
				make_shared<BlkBackwarded>(
					make_shared<BlkBackwarded>(
						make_shared<BlkForwarded>(
							block,
							key
						),
						key
					),
					key
				),
				key
			)
		)
	  )
{
}

pair<uint32_t, uint32_t> BlkDecrypted::value() const
{
	return block->value();
}
