// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <goost/Source.h>

namespace goost {
namespace magma { class Key; }
namespace gost89 {

class CFBSource final : public Source {
public:
	CFBSource(
		const std::shared_ptr<const Source> &source,
		const std::shared_ptr<const magma::Key> &key,
		uint64_t iv,
		const std::vector<std::byte> &plain
	);

	CFBSource(
		const std::shared_ptr<const Source> &source,
		const std::shared_ptr<const magma::Key> &key,
		uint64_t iv
	);

	std::pair<std::vector<std::byte>, std::shared_ptr<const Source>> read(
		size_t size
	) const override;

private:
	const std::shared_ptr<const Source> source;
	const std::shared_ptr<const magma::Key> key;
	const uint64_t iv;
	const std::vector<std::byte> plain;
};

}
}
