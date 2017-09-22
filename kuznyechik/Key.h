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
	// @todo #236 Key::Data::low and Key::Data::high should return pointer to Block
	class Data {
	public:
		virtual ~Data() = default;
		virtual BlkRaw low() const = 0;
		virtual BlkRaw high() const = 0;
	};

	explicit Key(const std::string &key_data);
	explicit Key(const std::shared_ptr<const Data> &key_data);

	std::unique_ptr<const Block> encrypt(const std::shared_ptr<const Block> &block) const;

private:
	const std::shared_ptr<const Block> k1;
	const std::shared_ptr<const Block> k2;
	const std::shared_ptr<const Block> k3;
	const std::shared_ptr<const Block> k4;
	const std::shared_ptr<const Block> k5;
	const std::shared_ptr<const Block> k6;
	const std::shared_ptr<const Block> k7;
	const std::shared_ptr<const Block> k8;
	const std::shared_ptr<const Block> k9;
	const std::shared_ptr<const Block> k10;

	std::shared_ptr<const Block> encryptStep(
		const std::shared_ptr<const Block> &block,
		const std::shared_ptr<const Block> &kn
	) const;
};

}
