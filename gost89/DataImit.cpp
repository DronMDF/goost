// Copyright (c) 2017 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "DataImit.h"
#include "ImitedBlock.h"

using namespace std;
using namespace gost89;
using namespace magma;

DataImit::DataImit(const vector<uint8_t> &data, const shared_ptr<const Key> &key)
	: data(data), key(key)
{
}

vector<uint8_t> DataImit::value() const
{
	vector<uint8_t> state(8);
	auto pdata = data;
	while (pdata.size() < 16) {
		pdata.push_back(0);
	}
	while (pdata.size() % 8 != 0) {
		pdata.push_back(0);
	}
	auto pi = pdata.begin();
	while (pi != pdata.end()) {
		for (auto &s : state) {
			s ^= *pi++;
		}
		const auto b = ImitedBlock(BlkRaw(state), key).value().value();
		reinterpret_cast<uint32_t *>(&state[0])[0] = b.first;
		reinterpret_cast<uint32_t *>(&state[0])[1] = b.second;
	}
	return state;
}

uint32_t DataImit::asUInt32() const
{
	const auto rv = value();
	return *reinterpret_cast<const uint32_t *>(&rv[0]);
}
