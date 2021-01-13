// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSinkText.h"
#include <limits>
#include <goost/Sink.h>
#include <goost/Source.h>
#include "TestSink.h"

using namespace std;
using namespace goost;

TestSinkText::TestSinkText(
	const shared_ptr<const Sink> &sink,
	const shared_ptr<const Source> &data
) : sink(sink), data(data)
{
}

string TestSinkText::asString() const
{
	const auto bytes = data->read(numeric_limits<size_t>::max());
	const auto out = sink->write(bytes.first)->finalize();
	return dynamic_pointer_cast<const TestSink>(out)->asHexString();
}
