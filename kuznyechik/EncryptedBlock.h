// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "BlkRaw.h"

namespace kuznyechik {

class Key;

// @todo #87:15min Need to introduce BlkRaw abstraction
//  EncryptedBlock block should be a Block.
//  Q: If block is a abstraction - value cannot return BlkRaw by value.
class EncryptedBlock final {
public:
	EncryptedBlock(const BlkRaw &block, const std::shared_ptr<const Key> &key);

	BlkRaw value() const;

private:
	const BlkRaw block;
	const std::shared_ptr<const Key> key;
};

}
