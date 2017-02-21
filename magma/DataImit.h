#include <memory>
#include <vector>

namespace magma {

class Key;

class DataImit {
public:
	DataImit(const std::vector<uint8_t> &data, const std::shared_ptr<const Key> &key);

	std::vector<uint8_t> value() const;
	uint32_t asUInt32() const;
private:
	const std::vector<uint8_t> data;
	const std::shared_ptr<const Key> key;
};

}
