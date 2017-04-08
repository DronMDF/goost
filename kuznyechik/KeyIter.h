#pragma once
#include <memory>
#include "Key.h"

namespace kuznyechik {

// @todo #59:30min KeyIter are very similar and it looks like copy-paste
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

class KeyIter3 final : public Key::Iter, private Operations {
public:
	explicit KeyIter3(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k1;
	const std::unique_ptr<const Key::Iter> k2;
};

class KeyIter4 final : public Key::Iter, private Operations {
public:
	explicit KeyIter4(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k1;
	const std::unique_ptr<const Key::Iter> k2;
};

class KeyIter5 final : public Key::Iter, private Operations {
public:
	explicit KeyIter5(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k3;
	const std::unique_ptr<const Key::Iter> k4;
};

class KeyIter6 final : public Key::Iter, private Operations {
public:
	explicit KeyIter6(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k3;
	const std::unique_ptr<const Key::Iter> k4;
};

class KeyIter7 final : public Key::Iter, private Operations {
public:
	explicit KeyIter7(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k5;
	const std::unique_ptr<const Key::Iter> k6;
};

class KeyIter8 final : public Key::Iter, private Operations {
public:
	explicit KeyIter8(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k5;
	const std::unique_ptr<const Key::Iter> k6;
};

class KeyIter9 final : public Key::Iter, private Operations {
public:
	explicit KeyIter9(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k7;
	const std::unique_ptr<const Key::Iter> k8;
};

class KeyIter10 final : public Key::Iter, private Operations {
public:
	explicit KeyIter10(const std::shared_ptr<const Key::Data> &key_data);
	Block value() const override;
private:
	const std::unique_ptr<const Key::Iter> k7;
	const std::unique_ptr<const Key::Iter> k8;
};

}
