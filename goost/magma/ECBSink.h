// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <goost/Sink.h>

namespace goost {
namespace magma {

class Key;

class ECBSink final : public Sink {
public:
	ECBSink(
		const std::shared_ptr<const Sink> &sink,
		const std::shared_ptr<const Key> &key
	);

	std::shared_ptr<const Sink> write(const std::vector<std::byte> &data) const override;
	std::shared_ptr<const Sink> finalize() const override;

private:
	const std::shared_ptr<const Sink> sink;
	const std::shared_ptr<const Key> key;
};

}  // namespace magma
}  // namespace goost

