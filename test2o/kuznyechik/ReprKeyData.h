// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>
#include <kuznyechik/Key.h>

// Representation for high block of key data
class ReprKeyDataHigh final : public oout::Representation {
public:
	explicit ReprKeyDataHigh(const std::shared_ptr<kuznyechik::Key::Data> &key);
	std::string asString() const override;
private:
	const std::shared_ptr<kuznyechik::Key::Data> key;
};

// Representation for low block of key data.
class ReprKeyDataLow final : public oout::Representation {
public:
	explicit ReprKeyDataLow(const std::shared_ptr<kuznyechik::Key::Data> &key);
	std::string asString() const override;
private:
	const std::shared_ptr<kuznyechik::Key::Data> key;
};
