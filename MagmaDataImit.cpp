
#include "MagmaDataImit.h"

using namespace std;

MagmaDataImit::MagmaDataImit(const vector<uint8_t> &data, const shared_ptr<const MagmaKey> &key)
	: data(data), key(key)
{
}

vector<uint8_t> MagmaDataImit::value() const
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
		for (auto &s: state) {
			s ^= *pi++;
		}
		state = key->imit(state);
	}
	return state;
}
