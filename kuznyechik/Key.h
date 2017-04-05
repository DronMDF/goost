#pragma once
#include <string>

namespace kuznyechik {

class Block;

class Key final {
public:
	class Data {
	public:
		virtual Block low() const = 0;
		virtual Block high() const = 0;
	};

	class Iter {
	public:
		virtual Block value() const = 0;
	};

	explicit Key(const std::string &key_data [[gnu::unused]]) {};
};

}

