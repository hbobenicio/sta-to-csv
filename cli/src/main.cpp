#include <iostream>
#include <cstdlib>
#include <cassert>
#include <memory>

#include "sta-parser.h"

static void printUsage()
{
	std::cerr << "Usage:\n";
	std::cerr << "  ./cli <REF.txt> <DATA.txt> <OUTPUT.csv>\n\n";
}

int main(int argc, char* argv[])
{
	if (argc != 4) {
		printUsage();
		return 1;
	}

	std::string refFilepath{argv[1]};
	std::string dataFilePath{argv[2]};
	std::string outputFilePath{argv[3]};

	STAParser parser{refFilepath, dataFilePath, outputFilePath};
/*
	auto filtrarEventosDestaque = [](const string& value) -> bool {
		if (value == "300300" || value == "300301" || value == "300302") {
			return true;
		}
		return false;
	};

	parser.setMultipleFilterMode(STAParser::MultipleFilterMode::OR);
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(1)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(2)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(3)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(4)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(5)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(6)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(7)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(8)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(9)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(10)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(11)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(12)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(13)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(14)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(15)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(16)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(17)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(18)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(19)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(20)"s, filtrarEventosDestaque});
*/
	parser.parse();

	return 0;
}

