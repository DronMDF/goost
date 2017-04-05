#pragma once
#include <memory>
#include "Key.h"

namespace kuznyechik {

class KeyIter1 final : public Key::Iter {
public:
	explicit KeyIter1(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::shared_ptr<const Key::Data> key_data;
};

class KeyIter2 final : public Key::Iter {
public:
	explicit KeyIter2(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::shared_ptr<const Key::Data> key_data;
};

};
