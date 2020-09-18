// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SboxByte.h"

namespace goost {
namespace magma {

class SboxByte64Tab final : public SboxByte::Tab {
public:
	SboxByte64Tab(const std::vector<uint8_t> &uz, int offset);

	uint32_t translate(int index) const override;
private:
	const std::vector<uint8_t> uz;
	int offset;
};

}  // namespace magma
}  // namespace goost
