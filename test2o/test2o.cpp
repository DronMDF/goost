#include <iostream>
#include <2out/CountError.h>
#include <2out/CountFailure.h>
#include <2out/JUnitXmlReport.h>
#include <2out/TestSuite.h>

using namespace std;
using namespace oout;

int main(int, char **)
{
	const auto result = TestSuite(
		list<shared_ptr<const Test>>{}
	).result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
