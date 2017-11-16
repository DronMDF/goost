// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <magma/BlkRaw.h>
#include <magma/Key.h>

namespace gost89 {

// @todo #352 ImitedBlock should give ptr to Block

// @todo #352 ImitedBlock should be Block

// @todo #352 ImitedBlock should named BlkImited

class ImitedBlock {
public:
	ImitedBlock(const magma::BlkRaw &block, const std::shared_ptr<const magma::Key> &key);

	magma::BlkRaw value() const;

private:
	const magma::BlkRaw block;
	const std::shared_ptr<const magma::Key> key;
};

}
