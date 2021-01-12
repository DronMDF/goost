// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <goost/magma/BlkRaw.h>
#include <goost/magma/LazyKey.h>

namespace goost {
namespace gost89 {

// @todo #352 ImitedBlock should give ptr to Block

// @todo #352 ImitedBlock should be Block

// @todo #352 ImitedBlock should named BlkImited

class ImitedBlock {
public:
	ImitedBlock(const magma::BlkRaw &block, const std::shared_ptr<const magma::LazyKey> &key);

	magma::BlkRaw value() const;

private:
	const magma::BlkRaw block;
	const std::shared_ptr<const magma::LazyKey> key;
};

}  // namespace gost89
}  // namespace goost
