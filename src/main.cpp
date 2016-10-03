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

	auto fieldsAreEqual = [](const string& a, const string& b) -> bool { return a == b; };
	STAFilter filter("GR-CODIGO-EVENTO(1)"s, fieldsAreEqual, "300300"s);

	parser.addFilter(filter);

	parser.parse();

	return 0;
}

