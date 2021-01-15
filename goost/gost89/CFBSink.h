// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <goost/Sink.h>

namespace goost {

namespace magma { class Key; }

namespace gost89 {

class CFBSink final : public Sink {
public:
	CFBSink(
		const std::shared_ptr<const Sink> &sink,
		const std::shared_ptr<const magma::Key> &key,
		uint64_t iv,
		const std::vector<std::byte> &plain
	);

	CFBSink(
		const std::shared_ptr<const Sink> &sink,
		const std::shared_ptr<const magma::Key> &key,
		uint64_t iv
	);

	std::shared_ptr<const Sink> write(const std::vector<std::byte> &data) const override;
	std::shared_ptr<const Sink> finalize() const override;

private:
	const std::shared_ptr<const Sink> sink;
	const std::shared_ptr<const magma::Key> key;
	const uint64_t iv;
	const std::vector<std::byte> plain;
};

}  // namespace gost89
}  // namespace goost
