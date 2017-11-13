// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <kuznyechik/Block.h>
#include <kuznyechik/Key.h>

namespace kuznyechik {

// High block of key data
class BlkKeyDataHigh final : public Block {
public:
	explicit BlkKeyDataHigh(const std::shared_ptr<const Key::Data> &key);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Key::Data> key;
};

// Low block of key data.
class BlkKeyDataLow final : public Block {
public:
	explicit BlkKeyDataLow(const std::shared_ptr<const Key::Data> &key);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Key::Data> key;
};

}
