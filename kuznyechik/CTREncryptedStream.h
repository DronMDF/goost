#pragma once
#include <memory>
#include "Stream.h"

namespace kuznyechik {

class Block;
class BlockIterator;
class Key;

// @todo #82:30min CTREncryptedStream is a generic alg.
//  May be share this code with magma with templates?

// @todo #93:15min Rename CTREncryptedStream to StCTREncrypted
class CTREncryptedStream final : public Stream {
public:
	CTREncryptedStream(
		const std::shared_ptr<const Stream> &stream,
		const std::shared_ptr<const Key> &key,
		const uint64_t iv
	);

	virtual std::shared_ptr<const BlockIterator> iter() const override;

private:
	const std::shared_ptr<const Stream> stream;
	const std::shared_ptr<const Key> key;
	const uint64_t iv;
};

}
