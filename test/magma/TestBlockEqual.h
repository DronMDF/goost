// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <2out/Representation.h>
#include <2out/Test.h>
#include <goost/magma/Block.h>

namespace magma {

// @todo #378 Add magma::BlockMatch with 2out::MatchTest instead TestBlockEqual
class TestBlockEqual final : public oout::Test {
public:
	/// Primary ctor
	TestBlockEqual(
		const std::shared_ptr<const oout::Representation> &a,
		const std::string &b
	);

	TestBlockEqual(
		const std::shared_ptr<const goost::magma::Block> &a,
		const std::shared_ptr<const goost::magma::Block> &b
	);

	TestBlockEqual(const std::shared_ptr<const goost::magma::Block> &a, const std::string &b);

	/// Get result
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> test;
};

}  // namespace magma
