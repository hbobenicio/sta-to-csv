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

	auto filtrarEventosDestaque = [](const string& value) -> bool {
		if (value == "300300" || value == "300301" || value == "300302") {
			return true;
		}
		return false;
	};

	parser.setMultipleFilterMode(STAParser::MultipleFilterMode::OR);
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(1)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(2)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(3)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(4)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(5)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(6)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(7)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(8)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(9)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(10)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(11)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(12)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(13)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(14)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(15)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(16)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(17)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(18)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(19)"s, filtrarEventosDestaque));
	parser.addFilter(STAFilter("GR-CODIGO-EVENTO(20)"s, filtrarEventosDestaque));

	parser.parse();

	return 0;
}

