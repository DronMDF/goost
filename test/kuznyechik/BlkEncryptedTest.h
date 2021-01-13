// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>
#include <goost/kuznyechik/Key.h>

namespace kuznyechik {

class BlkEncryptedTest final : public oout::Test {
public:
	BlkEncryptedTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const goost::kuznyechik::Key> key;
	const std::shared_ptr<const oout::Test> tests;
};

}  // namespace kuznyechik
