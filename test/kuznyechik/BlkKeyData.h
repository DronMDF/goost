// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <goost/kuznyechik/Block.h>
#include <goost/kuznyechik/Key.h>

namespace kuznyechik {

// High block of key data
class BlkKeyDataHigh final : public goost::kuznyechik::Block {
public:
	explicit BlkKeyDataHigh(const std::shared_ptr<const goost::kuznyechik::Key::Data> &key);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const goost::kuznyechik::Key::Data> key;
};

// Low block of key data.
class BlkKeyDataLow final : public goost::kuznyechik::Block {
public:
	explicit BlkKeyDataLow(const std::shared_ptr<const goost::kuznyechik::Key::Data> &key);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const goost::kuznyechik::Key::Data> key;
};

}  // namespace kuznyechik
