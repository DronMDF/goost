// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>
#include <kuznyechik/Key.h>

namespace kuznyechik {

class KeyIterTest final : public oout::Test {
public:
	KeyIterTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const kuznyechik::Key::Data> key_data;
	const std::shared_ptr<const oout::Test> tests;
};

}