#include "sta-parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

STAParser::STAParser(const string& refFilePath, const string& dataFilePath)
    : refFilePath(refFilePath), dataFilePath(dataFilePath)
{
}

STAParser::~STAParser() {
}

void STAParser::parse() {
	parseRef();
	parseData();
}

void STAParser::parseRef() {
	ifstream file(refFilePath.c_str());

	if (file) {
		string fieldName, fieldSize;
		char fieldType;

        FieldInfo info;
		while(file >> fieldName >> fieldType >> fieldSize) {
            info.name = fieldName;
            info.size = fieldSize;
            info.type = fieldType;

            fieldsInfo.push_back(info);
		}

		file.close();
	}
}

void STAParser::parseData() {
	ifstream file(dataFilePath.c_str());

	if (file) {
		// writeHeader();

		for (string line; getline(file, line); ) {
			proccessLine(line);
		}

		file.close();
	}
}

void STAParser::proccessLine(const string& line) {
	int offset = 0;
	for (auto it = fieldsInfo.begin(); it != fieldsInfo.end(); it++) {
		int fieldLength = it->readLength();
		string fieldValue = line.substr(offset, fieldLength);

		writeField(*it, fieldValue);

		offset += fieldLength;
	}
	cout << endl;
}

void STAParser::writeField(const FieldInfo& info, const std::string& fieldValue) {
	if (info.type == 'A') {
		cout << "\"" << fieldValue << "\";";
	} else if (info.type == 'N') {
		// TODO Formatar considerando vírgula
		cout << "" << fieldValue << ";";
	} else {
		cout << "" << fieldValue << ";";
	}
}
