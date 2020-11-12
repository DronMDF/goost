// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Text.h>

namespace goost {
	class Sink;
	class Source;
}

// This class require sink with TestSink underlaing
class TestSinkText final : public oout::Text {
public:
	TestSinkText(
		const std::shared_ptr<const goost::Sink> &sink,
		const std::shared_ptr<const goost::Source> &data
	);

	std::string asString() const override;
private:
	const std::shared_ptr<const goost::Sink> sink;
	const std::shared_ptr<const goost::Source> data;
};
