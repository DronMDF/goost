#include "SboxByte.h"

namespace magma {

class SboxByte64Tab final : public SboxByte::Tab {
public:
	SboxByte64Tab(const std::vector<uint8_t> &uz, int offset);

	uint32_t translate(int index) const override;
private:
	const std::vector<uint8_t> uz;
	int offset;
};

}
