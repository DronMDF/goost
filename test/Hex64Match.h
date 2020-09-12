// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <2out/Match.h>

// This matcher get expected string as 64-bin integer
// This form used in GOST examples.
class Hex64Match final : public oout::Match {
public:
	explicit Hex64Match(const std::string &hex);

	std::unique_ptr<const oout::Result> match(
		const std::shared_ptr<const oout::Text> &b
	) const override;

private:
	const std::string hex;
};
