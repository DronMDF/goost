class MagmaSbox {
public:
	MagmaSbox(const std::vector<uint8_t> &uz);
	MagmaSbox(const std::vector<uint8_t> &tab1,
		const std::vector<uint8_t> &tab2,
		const std::vector<uint8_t> &tab3,
		const std::vector<uint8_t> &tab4);

	uint32_t transform(uint32_t v) const;

private:
	static std::vector<uint8_t> expand_tab(const std::vector<uint32_t> &uz, int offset);

	const std::vector<uint8_t> tab1;
	const std::vector<uint8_t> tab2;
	const std::vector<uint8_t> tab3;
	const std::vector<uint8_t> tab4;
};
