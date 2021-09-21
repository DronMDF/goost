// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "HexContainer.h"
#include <cstring>
#include <exception>
#include <sstream>

using namespace std;
using namespace goost::magma;

HexContainer::HexContainer(const string &hex)
	: hex(hex)
{
}

vector<byte> HexContainer::key() const
{
	if (hex.size() != 64) {
		throw runtime_error("Wrong key size");
	}

	vector<byte> key(32);
	istringstream in(hex);
	for (auto &k : key) {
		char c[2];
		in >> c[0] >> c[1];
		k = byte(stoul(string(&c[0], 2), nullptr, 16));
	}
	return key;
}

vector<byte> HexContainer::mask() const
{
	return vector<byte>(32, byte(0));
}

vector<byte> HexContainer::sbox() const
{
	const uint8_t sbox_r3412[64] = {
		0x6C, 0xCB, 0x57, 0x18, 0x84, 0x83, 0xDF, 0x7E,
		0x26, 0x25, 0xF5, 0xE2, 0x32, 0x18, 0x6A, 0xD5,
		0x9A, 0xD2, 0x98, 0x06, 0xA5, 0x4F, 0x21, 0x59,
		0x5B, 0xFA, 0xC6, 0x81, 0xC9, 0x6D, 0xAD, 0x3C,
		0x1E, 0x7E, 0xB0, 0x4F, 0xE8, 0x01, 0x79, 0xF4,
		0x4D, 0xA7, 0x83, 0xAB, 0x77, 0x54, 0x1E, 0x60,
		0xB0, 0x3C, 0x4B, 0x9D, 0xD3, 0xE9, 0x34, 0xCA,
		0x0F, 0x96, 0xE2, 0xB3, 0xF1, 0xB0, 0x0C, 0x27
	};
	vector<byte> sbox(64);
	memcpy(&sbox[0], &sbox_r3412[0], 64);
	return sbox;
}
