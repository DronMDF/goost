// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprKeyData.h"
#include <iomanip>
#include <sstream>
#include <arpa/inet.h>
#include <goost/magma/KeyData.h>

using namespace std;
using namespace magma;

ReprKeyData::ReprKeyData(const shared_ptr<const KeyData> &key_data)
	: key_data(key_data)
{
}

string ReprKeyData::asString() const
{
	ostringstream out;
	for (int i = 0; i < 8; i++) {
		out << hex << setfill('0') << setw(8) << htonl(key_data->key(i));
	}

	return out.str();
}

