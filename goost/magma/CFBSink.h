// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <goost/Sink.h>

namespace magma {

class CFBSink final : public Sink {
public:
	explicit CFBSink(const std::shared_ptr<const Sink> &sink);

	std::shared_ptr<const Sink> write(const std::vector<std::byte> &data) const override;
	std::shared_ptr<const Sink> finalize() const override;
private:
	const std::shared_ptr<const Sink> sink;

	std::vector<std::byte> to_bytes(const std::string &str) const;
};

}
