// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>
#include <kuznyechik/Key.h>

namespace kuznyechik {

// @todo #174 rename EncryptedBlockTest to BlkEncryptedTest
class EncryptedBlockTest final : public oout::Test {
public:
	EncryptedBlockTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const kuznyechik::Key> key;
	const std::shared_ptr<const oout::Test> tests;
};

}
