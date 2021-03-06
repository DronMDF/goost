// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include <2out/Match.h>

class HexMatch final : public oout::Match {
public:
	explicit HexMatch(const std::string &hex);

	std::unique_ptr<const oout::Result> match(
		const std::shared_ptr<const oout::Text> &b
	) const override;

private:
	const std::string hex;
};
