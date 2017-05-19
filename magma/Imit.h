// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace magma {

class Block;
class DataStream;
class Key;

class Imit final {
public:
	Imit(const std::shared_ptr<const DataStream> &data, const std::shared_ptr<const Key> &key);

	Block value() const;
private:
	const std::shared_ptr<const DataStream> data;
	const std::shared_ptr<const Key> key;
};

}
