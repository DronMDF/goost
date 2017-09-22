// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include <memory>
#include "Block.h"

namespace kuznyechik {

class BlkRaw;

class Key final {
public:
	class Data {
	public:
		virtual ~Data() = default;
		virtual BlkRaw low() const = 0;
		virtual BlkRaw high() const = 0;
	};

	// @todo #208 Key::Iter should be Block
	class Iter {
	public:
		virtual ~Iter() = default;
		virtual BlkRaw value() const = 0;
	};

	explicit Key(const std::string &key_data);
	explicit Key(const std::shared_ptr<const Data> &key_data);

	std::unique_ptr<const Block> encrypt(const std::shared_ptr<const Block> &block) const;

private:
	const std::unique_ptr<const Iter> k1;
	const std::unique_ptr<const Iter> k2;
	const std::unique_ptr<const Iter> k3;
	const std::unique_ptr<const Iter> k4;
	const std::unique_ptr<const Iter> k5;
	const std::unique_ptr<const Iter> k6;
	const std::unique_ptr<const Iter> k7;
	const std::unique_ptr<const Iter> k8;
	const std::unique_ptr<const Iter> k9;
	const std::unique_ptr<const Iter> k10;

	std::shared_ptr<const Block> encryptStep(
		const std::shared_ptr<const Block> &block,
		const std::unique_ptr<const Iter> &iter_key
	) const;
};

}
