// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace magma {

class BlkRaw;
class DataStream;
class Key;

// @todo #274 magma::Imit should be magma::Block
class Imit final {
public:
	Imit(const std::shared_ptr<const DataStream> &data, const std::shared_ptr<const Key> &key);

	BlkRaw value() const;
private:
	const std::shared_ptr<const DataStream> data;
	const std::shared_ptr<const Key> key;
};

}
