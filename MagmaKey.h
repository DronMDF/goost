
class MagmaKey {
public:
	MagmaKey(const std::vector<uint8_t> &key, const std::shared_ptr<const MagmaSbox> &sbox);
	MagmaKey(const std::vector<uint32_t> &key, const std::shared_ptr<const MagmaSbox> &sbox);

	std::vector<uint8_t> imit(const std::vector<uint8_t> &block) const;

private:
	static std::vector<uint32_t> fromBytes(const std::vector<uint8_t> &key);
};
