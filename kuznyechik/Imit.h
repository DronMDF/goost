// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace kuznyechik {

class BlkRaw;
class Key;
class Stream;

// @todo #174 Imit should have Block type
class Imit {
public:
	Imit(const std::shared_ptr<const Stream> &data, const std::shared_ptr<const Key> &key);
	BlkRaw value() const;
private:
	const std::shared_ptr<const Stream> data;
	const std::shared_ptr<const Key> key;
};

}

