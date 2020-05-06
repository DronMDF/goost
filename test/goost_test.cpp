// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/CountError.h>
#include <2out/CountFailure.h>
#include <2out/JUnitXmlReport.h>
#include <2out/TestSuite.h>
#include "kuznyechik/Test.h"
#include "magma/Test.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const shared_ptr<const Result> result = TestSuite(
		make_shared<kuznyechik::Test>(),
		make_shared<magma::Test>()
	).result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
