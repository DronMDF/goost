#include <memory>
#include <vector>

class MagmaDataImit {
public:
	MagmaDataImit(const std::vector<uint8_t> &data, const std::shared_ptr<const MagmaKey> &key);
	std::vector<uint8_t> value() const;
private:
	const std::vector<uint8_t> data;
	const std::shared_ptr<const MagmaKey> key;
};
