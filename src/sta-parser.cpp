#include "sta-parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "sta-converter.h"
#include "sta-register.h"

using namespace std;

STAParser::STAParser(const string& refFilePath, const string& dataFilePath)
    : refFilePath(refFilePath), dataFilePath(dataFilePath)
{
}

void STAParser::parse() {
	parseRef();
	parseData();
}

void STAParser::parseRef() {
	ifstream file(this->refFilePath.c_str());

	if (file && file.is_open()) {
		string fieldName, fieldSize;
		char fieldType;

		while(file >> fieldName >> fieldType >> fieldSize) {
			FieldInfo info(fieldName, fieldType, fieldSize);
            this->fieldsInfo.push_back(info);
		}

		file.close();
	}
}

void STAParser::parseData() {
	ifstream file(this->dataFilePath.c_str());

	if (file && file.is_open()) {
		writeHeader();

		for (string line; getline(file, line); ) {
			proccessLine(line);
		}

		file.close();
	}
}

void STAParser::writeHeader() {
	for (auto& info: this->fieldsInfo) {
		cout << "\"" << info.name << "\";";
	}
	cout << endl;
}

void STAParser::proccessLine(const string& line) {
	int offset = 0;
	STARegister reg;
	for (auto& info: this->fieldsInfo) {
		int fieldLength = info.readLength();
		string fieldValue = line.substr(offset, fieldLength);

		reg.addField(info, fieldValue);

		offset += fieldLength;
	}

	if (acceptFilter(reg)) {
		writeRegister(reg);
	}
}

void STAParser::writeRegister(const STARegister& reg) {
	for (auto& info: this->fieldsInfo) {
		writeField(info, reg.getValue(info.name));
	}
	cout << endl;
}

void STAParser::writeField(const FieldInfo& info, const std::string& fieldValue) {
	if (info.type == 'A') {
		cout << "\"" << fieldValue << "\";";
	} else if (info.type == 'N' || info.type == 'P') {
		cout << "" << STAConverter::formatDecimal(info, fieldValue) << ";";
	} else {
		cout << "" << fieldValue << ";";
	}
}

void STAParser::addFilter(const STAFilter& filter) {
	this->filters.push_back(filter);
}

void STAParser::setMultipleFilterMode(const MultipleFilterMode& mode) {
	this->multipleFilterMode = mode;
}

bool STAParser::acceptFilter(const STARegister& reg) const {
	if (this->multipleFilterMode == AND) {
		return acceptFilterModeAnd(reg);
	}
	if (this->multipleFilterMode == OR) {
		return acceptFilterModeOr(reg);
	}
	return false;
}

bool STAParser::acceptFilterModeAnd(const STARegister& reg) const {
	for (auto& filter : this->filters) {
		auto op = filter.getComparisonFunction();
		string registerValue = reg.getValue(filter.getFieldName());

		bool accepted = op(registerValue);
		if (!accepted) {
			return false;
		}
	}
	return true;
}

bool STAParser::acceptFilterModeOr(const STARegister& reg) const {
	for (auto& filter : this->filters) {
		auto op = filter.getComparisonFunction();
		string registerValue = reg.getValue(filter.getFieldName());

		bool accepted = op(registerValue);
		if (accepted) {
			return true;
		}
	}
	return false;
}

void STAParser::setStrictConvertion(bool strictConvertion) {
  this->strictConvertion = strictConvertion;
}
