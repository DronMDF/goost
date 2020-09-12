// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <goost/Sink.h>

class TestSink final : public Sink {
public:
	explicit TestSink(const std::vector<std::byte> &data);
	TestSink();

	std::shared_ptr<const Sink> write(const std::vector<std::byte> &data) const override;
	std::shared_ptr<const Sink> finalize() const override;

	std::string asHexString() const;
private:
	const std::vector<std::byte> data;
};