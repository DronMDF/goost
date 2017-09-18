// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>

namespace kuznyechik {

// @todo #234 Add kuznyechik::TestBlockEqual class for avoid imm Representation
//  This should be wrap above TestEqual and ReprBlock

class Test final : public oout::Test {
public:
	Test();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> tests;
};

}
