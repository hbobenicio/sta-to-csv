#include <iostream>
#include <cstdlib>
#include <cassert>
#include "sta-parser.h"

using namespace std;

int main(int argc, char* argv[])
{
	assert(argc == 3);

	string refFilepath = string(argv[1]);
	string dataFilePath = string(argv[2]);

	STAParser parser(refFilepath, dataFilePath);
	parser.setMultipleFilterMode(OR);

	auto fieldsAreEqual = [](const string& a, const string& b) -> bool { return a == b; };

	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(1)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(2)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(3)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(4)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(5)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(6)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(7)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(8)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(9)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(10)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(11)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(12)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(13)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(14)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(15)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(16)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(17)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(18)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(19)"s, fieldsAreEqual, "300300"s));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(20)"s, fieldsAreEqual, "300300"s));


	parser.parse();

	return 0;
}

