#pragma once
#include <memory>
#include <magma/Block.h>
#include <magma/Key.h>

namespace gost89 {

class ImitedBlock {
public:
	ImitedBlock(const magma::Block &block, const std::shared_ptr<const magma::Key> &key);

	magma::Block value() const;

private:
	const magma::Block block;
	const std::shared_ptr<const magma::Key> key;
};

}
