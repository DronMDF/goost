#pragma once
#include "Sbox.h"
#include <memory>

namespace magma {

// Sbox decorator for <<<11 operation
class SboxTwisted : public Sbox {
public:
	explicit SboxTwisted(const std::shared_ptr<const Sbox> &sbox);

	virtual uint32_t transform(uint32_t value) const override;
private:
	const std::shared_ptr<const Sbox> sbox;
};

}