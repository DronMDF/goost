// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/2out.h>
#include "gost89/Test.h"
#include "kuznyechik/Test.h"
#include "magma/Test.h"
#include "Hex64SourceTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const shared_ptr<const Result> result = TestSuite(
		make_shared<Hex64SourceTest>(),
		make_shared<goost::gost89::Test>(),
		make_shared<kuznyechik::Test>(),
		make_shared<magma::Test>()
	).result();

	cout << OoutReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
