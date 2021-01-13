// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <goost/Source.h>

namespace goost {
namespace magma {

class LazyKey;

class ECBSource final : public Source {
public:
	ECBSource(
		const std::shared_ptr<const Source> &source,
		const std::shared_ptr<const LazyKey> &key
	);

	std::pair<std::vector<std::byte>, std::shared_ptr<const Source>> read(
		size_t size
	) const override;

private:
	const std::shared_ptr<const Source> source;
	const std::shared_ptr<const LazyKey> key;
};

}
}
