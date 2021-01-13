// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/2out.h>

namespace goost { class Source; }

class SourceText final : public oout::Text {
public:
	explicit SourceText(const std::shared_ptr<const goost::Source> &source);
	std::string asString() const override;
private:
	const std::shared_ptr<const goost::Source> source;
};
