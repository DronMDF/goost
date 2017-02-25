#pragma once
#include "Sbox.h"
#include <memory>

namespace magma {

class SboxR3412 : public Sbox {
public:
	SboxR3412();

	virtual uint32_t transform(uint32_t value) const override;
private:
	const std::shared_ptr<const Sbox> sbox;
};

}
