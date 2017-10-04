// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace magma {

class BlkRaw;

// @todo #274 rename magma::BlockIterator to magma::Iterator
// @todo #274 magma::Iterator should be magma::Block
class BlockIterator {
public:
	virtual ~BlockIterator() = default;

	virtual bool last() const = 0;
	virtual size_t size() const = 0;
	virtual BlkRaw value() const = 0;
	virtual std::shared_ptr<const BlockIterator> next() const = 0;
};

}
