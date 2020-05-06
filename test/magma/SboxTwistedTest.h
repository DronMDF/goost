// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/Result.h>

namespace magma {

class Sbox;

class SboxTwistedTest final : public oout::Test {
public:
	SboxTwistedTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const Sbox> sbox;
	const std::shared_ptr<const oout::Test> tests;
};

}  // namespace magma
