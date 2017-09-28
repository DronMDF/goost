// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <2out/Representation.h>
#include <2out/Test.h>
#include <kuznyechik/Block.h>

namespace kuznyechik {

class TestBlockEqual final : public oout::Test {
public:
	/// Primary ctor
	TestBlockEqual(
		const std::shared_ptr<const oout::Representation> &a,
		const std::shared_ptr<const oout::Representation> &b
	);

	TestBlockEqual(
		const std::shared_ptr<const Block> &a,
		const std::shared_ptr<const Block> &b
	);

	TestBlockEqual(const std::shared_ptr<const Block> &a, const std::string &b);

	/// Get result
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> test;
};

}
