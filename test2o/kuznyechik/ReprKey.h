#pragma once
#include <memory>
#include <2out/Representation.h>
#include <kuznyechik/Key.h>

// Representation of high key part.
class ReprKeyHigh final : public oout::Representation {
public:
	ReprKeyHigh(const std::shared_ptr<kuznyechik::Key::Data> &key);
	std::string asString() const override;
private:
	const std::shared_ptr<kuznyechik::Key::Data> key;
};

// Representation of low key part.
class ReprKeyLow final : public oout::Representation {
public:
	ReprKeyLow(const std::shared_ptr<kuznyechik::Key::Data> &key);
	std::string asString() const override;
private:
	const std::shared_ptr<kuznyechik::Key::Data> key;
};
