// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

namespace magma {

class Stream;

class ReprStream final : public oout::Representation {
public:
	explicit ReprStream(const std::shared_ptr<const Stream> &stream);
	std::string asString() const override;
private:
	const std::shared_ptr<const Stream> stream;
};

}