// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Text.h>
#include <goost/magma/Stream.h>

namespace magma {

class ReprStream final : public oout::Text {
public:
	explicit ReprStream(const std::shared_ptr<const goost::magma::Stream> &stream);
	std::string asString() const override;
private:
	const std::shared_ptr<const goost::magma::Stream> stream;
};

}  // namespace magma
