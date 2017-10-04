// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "BlkRaw.h"

namespace magma {

class Key;

// @todo #274 rename magma::EncryptedBlock to magma::BlkEncrypted
// @todo #274 magma::BlkEncrypted should take pointer to magma::Block
class EncryptedBlock {
public:
	EncryptedBlock(const BlkRaw &block, const std::shared_ptr<const Key> &key);

	BlkRaw value() const;

private:
	const BlkRaw block;
	const std::shared_ptr<const Key> key;
};

}
