// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>

namespace magma {

class KeyDataNativeTest final : public oout::Test {
public:
	KeyDataNativeTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> tests;
};

}  // namespace magma
