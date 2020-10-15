// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include <goost/Source.h>

class Hex64Source final : public goost::Source {
public:
	explicit Hex64Source(const std::string &str);
	// Query size should be multiple to 16 hex char, spaces available
	std::pair<std::vector<std::byte>, std::shared_ptr<const Source>> read(
		size_t size
	) const override;
private:
	const std::string str;
};
