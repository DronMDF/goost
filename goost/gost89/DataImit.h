// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <vector>
#include <goost/magma/Key.h>

namespace gost89 {

class DataImit {
public:
	DataImit(const std::vector<uint8_t> &data, const std::shared_ptr<const magma::Key> &key);

	std::vector<uint8_t> value() const;
	uint32_t asUInt32() const;
private:
	const std::vector<uint8_t> data;
	const std::shared_ptr<const magma::Key> key;
};

}
