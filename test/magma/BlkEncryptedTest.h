// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>
#include <magma/Key.h>

namespace magma {

class BlkEncryptedTest final : public oout::Test {
public:
	BlkEncryptedTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const Key> key1;
	const std::shared_ptr<const Key> key2;
	const std::shared_ptr<const oout::Test> tests;
};

}  // namespace magma
