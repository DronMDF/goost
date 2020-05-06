// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprStream.h"
#include <iomanip>
#include <sstream>
#include <arpa/inet.h>
#include <goost/magma/Iterator.h>
#include <goost/magma/Stream.h>

using namespace std;
using namespace magma;

ReprStream::ReprStream(const shared_ptr<const Stream> &stream)
	: stream(stream)
{
}

string ReprStream::asString() const
{
	ostringstream out;
	auto iter = stream->iter();

	while (true) {
		const auto iv = iter->value();
		out << hex << setfill('0') << setw(8) << htonl(iv.first);
		out << setw(8) << htonl(iv.second);
		if (iter->last()) {
			break;
		}
		iter = iter->next();
	}

	return out.str();
}
