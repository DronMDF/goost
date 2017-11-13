// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>
#include <kuznyechik/Key.h>

namespace kuznyechik {

class BlkIterKeyTest final : public oout::Test {
public:
	BlkIterKeyTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const kuznyechik::Key::Data> key_data;
	const std::shared_ptr<const Block> k1;
	const std::shared_ptr<const Block> k2;
	const std::shared_ptr<const Block> k3;
	const std::shared_ptr<const Block> k4;
	const std::shared_ptr<const Block> k5;
	const std::shared_ptr<const Block> k6;
	const std::shared_ptr<const Block> k7;
	const std::shared_ptr<const Block> k8;
	const std::shared_ptr<const Block> k9;
	const std::shared_ptr<const Block> k10;
	const std::shared_ptr<const oout::Test> tests;
};

}
