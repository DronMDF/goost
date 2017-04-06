#include "RBlock.h"
#include <array>
#include <cstring>

using namespace std;
using namespace kuznyechik;

RBlock::RBlock(const Block &block)
	: block(block)
{
}

Block RBlock::value() const
{
	constexpr int k[16] = {
		1, 148, 32, 133, 16, 194, 192, 1, 251, 1, 192, 194, 16, 133, 32, 148
	};
	array<uint8_t, 17> data;
	memcpy(&data[0], &block.low, sizeof(block.low));
	memcpy(&data[8], &block.high, sizeof(block.high));
	int sum = 0;
	for (int i = 0; i < 16; i++) {
		sum ^= data[i] * k[i];
	}
	data[16] = sum;
	return Block(&data[1]);
}
