#pragma once
#include <memory>
#include "Key.h"

namespace kuznyechik {

// @todo: Remove KeyIterPrimitives, this is a utility class
// Need to introduce Small classes for transformed blocks
class KeyIterPrimitives {
public:
	Block S(const Block &a) const;
	Block L(const Block &a) const;
};

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

class KeyIter3 final : public Key::Iter, private KeyIterPrimitives {
public:
	explicit KeyIter3(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k1;
	const std::unique_ptr<const Key::Iter> k2;
};

class KeyIter4 final : public Key::Iter, private KeyIterPrimitives {
public:
	explicit KeyIter4(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k1;
	const std::unique_ptr<const Key::Iter> k2;
};

}
