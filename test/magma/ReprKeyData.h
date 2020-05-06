// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

namespace magma {

class KeyData;

class ReprKeyData final : public oout::Representation {
public:
	explicit ReprKeyData(const std::shared_ptr<const KeyData> &key_data);
	std::string asString() const override;
private:
	const std::shared_ptr<const KeyData> key_data;
};

}  // namespace magma
