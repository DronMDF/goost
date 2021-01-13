// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Stream.h"

namespace goost {
namespace kuznyechik {

class BlkRaw;
class BlockIterator;
class Key;

// @todo #82:30min StCTREncrypted is a generic alg.
//  May be share this code with magma with templates?
class StCTREncrypted final : public Stream {
public:
	StCTREncrypted(
		const std::shared_ptr<const Stream> &stream,
		const std::shared_ptr<const Key> &key,
		const uint64_t iv
	);

	std::shared_ptr<const Iterator> iter() const override;

private:
	const std::shared_ptr<const Stream> stream;
	const std::shared_ptr<const Key> key;
	const uint64_t iv;
};

}  // namespace kuznyechik
}  // namespace goost
