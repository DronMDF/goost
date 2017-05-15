#pragma once
#include <string>
#include <memory>

namespace kuznyechik {

class Block;

class Key final {
public:
	class Data {
	public:
		virtual ~Data() = default;
		virtual Block low() const = 0;
		virtual Block high() const = 0;
	};

	class Iter {
	public:
		virtual ~Iter() = default;
		virtual Block value() const = 0;
	};

	explicit Key(const std::string &key_data);
	explicit Key(const std::shared_ptr<const Data> &key_data);

	Block encrypt(const Block &block) const;

private:
	const std::unique_ptr<const Iter> k1;
	const std::unique_ptr<const Iter> k2;
	const std::unique_ptr<const Iter> k3;
	const std::unique_ptr<const Iter> k4;
	const std::unique_ptr<const Iter> k5;
	const std::unique_ptr<const Iter> k6;
	const std::unique_ptr<const Iter> k7;
	const std::unique_ptr<const Iter> k8;
	const std::unique_ptr<const Iter> k9;
	const std::unique_ptr<const Iter> k10;
};

}
