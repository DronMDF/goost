// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlkEncrypted.h"
#include "BlkBackwarded.h"
#include "BlkForwarded.h"
#include "BlkSwapped.h"

using namespace std;
using namespace goost::magma;

BlkEncrypted::BlkEncrypted(const shared_ptr<const Block> &block, const shared_ptr<const LazyKey> &key)
	: block(
		make_shared<BlkSwapped>(
			make_shared<BlkBackwarded>(
				make_shared<BlkForwarded>(
					make_shared<BlkForwarded>(
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

pair<uint32_t, uint32_t> BlkEncrypted::value() const
{
	return block->value();
}
