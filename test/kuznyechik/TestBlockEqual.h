// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <2out/Text.h>
#include <2out/Test.h>
#include <goost/kuznyechik/Block.h>

namespace kuznyechik {

// @todo #378 Add kuznyechik::BlockMatch with 2out::MatchTest instead TestBlockEqual
class TestBlockEqual final : public oout::Test {
public:
	/// Primary ctor
	TestBlockEqual(
		const std::shared_ptr<const oout::Text> &a,
		const std::string &b
	);

	TestBlockEqual(
		const std::shared_ptr<const goost::kuznyechik::Block> &a,
		const std::shared_ptr<const goost::kuznyechik::Block> &b
	);

	TestBlockEqual(const std::shared_ptr<const goost::kuznyechik::Block> &a, const std::string &b);

	/// Get result
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> test;
};

}  // namespace kuznyechik
