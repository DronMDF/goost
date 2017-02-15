#include <memory>
#include <vector>

class MagmaKey;

class MagmaDataImit {
public:
	MagmaDataImit(const std::vector<uint8_t> &data, const std::shared_ptr<const MagmaKey> &key);

	std::vector<uint8_t> value() const;
	uint32_t asUInt32() const;
private:
	const std::vector<uint8_t> data;
	const std::shared_ptr<const MagmaKey> key;
};
