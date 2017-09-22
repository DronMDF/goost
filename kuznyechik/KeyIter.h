// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Block.h"
#include "Key.h"

namespace kuznyechik {

class KeyIter1 final : public Block {
public:
	explicit KeyIter1(const std::shared_ptr<const Key::Data> &key_data);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Key::Data> key_data;
};

class KeyIter2 final : public Block {
public:
	explicit KeyIter2(const std::shared_ptr<const Key::Data> &key_data);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Key::Data> key_data;
};

// @todo #71:30min KeyIterAny is not final
//  It is a base class for KeyIter2-10, this is a code sharing.
//  But I can't right named him for agregate
class KeyIterAny: public Block {
public:
	KeyIterAny(const std::shared_ptr<const Key::Data> &key_data, int iter);
	std::pair<uint64_t, uint64_t> value() const override;
private:
	const std::shared_ptr<const Block> k1;
	const std::shared_ptr<const Block> k2;
	const int iter;

	std::shared_ptr<const Block> generate(
		const std::shared_ptr<const Block> &a,
		const std::shared_ptr<const Block> &b,
		int iter
	) const;
};

class KeyIter3 final : public KeyIterAny {
public:
	explicit KeyIter3(const std::shared_ptr<const Key::Data> &key_data);
};

class KeyIter4 final : public KeyIterAny {
public:
	explicit KeyIter4(const std::shared_ptr<const Key::Data> &key_data);
};

class KeyIter5 final : public KeyIterAny {
public:
	explicit KeyIter5(const std::shared_ptr<const Key::Data> &key_data);
};

class KeyIter6 final : public KeyIterAny {
public:
	explicit KeyIter6(const std::shared_ptr<const Key::Data> &key_data);
};

class KeyIter7 final : public KeyIterAny {
public:
	explicit KeyIter7(const std::shared_ptr<const Key::Data> &key_data);
};

class KeyIter8 final : public KeyIterAny {
public:
	explicit KeyIter8(const std::shared_ptr<const Key::Data> &key_data);
};

class KeyIter9 final : public KeyIterAny {
public:
	explicit KeyIter9(const std::shared_ptr<const Key::Data> &key_data);
};

class KeyIter10 final : public KeyIterAny {
public:
	explicit KeyIter10(const std::shared_ptr<const Key::Data> &key_data);
};

}
