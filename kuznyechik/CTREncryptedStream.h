#pragma once
#include <memory>

namespace kuznyechik {

class Block;
class BlockIterator;
class DataStream;
class Key;

// @todo #82:30min CTREncryptedStream is a generic alg.
//  May be share this code with magma with templates?
class CTREncryptedStream final {
public:
	CTREncryptedStream(
		const std::shared_ptr<const DataStream> &stream,
		const std::shared_ptr<const Key> &key,
		const uint64_t iv
	);

	std::shared_ptr<const BlockIterator> iter() const;

private:
	const std::shared_ptr<const DataStream> stream;
	const std::shared_ptr<const Key> key;
	const uint64_t iv;
};

}
