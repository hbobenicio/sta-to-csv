#include "sta-parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "sta-converter.h"
#include "sta-register.h"

STAParser::STAParser(const std::string& refFilePath, const std::string& dataFilePath, const std::string& outputFilePath)
	: refFilePath(refFilePath), dataFilePath(dataFilePath), outputFilePath(outputFilePath)
{
}

STAParser::~STAParser() {
	if (this->outputFile.is_open()) {
		this->outputFile.close();
	}
}

void STAParser::parse() {
	parseRef();
	parseData();
}

void STAParser::parseRef() {
	std::ifstream file(this->refFilePath.c_str());

	if (file && file.is_open()) {
		std::string fieldName, fieldSize;
		char fieldType;

		while(file >> fieldName >> fieldType >> fieldSize) {
			FieldInfo info(fieldName, fieldType, fieldSize);
            this->fieldsInfo.push_back(info);
		}

		file.close();

		if(!validateFilters()) {
			// TODO Make it return to the user as an std::runtime_error
			std::cerr << "Invalid filters. Aborting.\n";
			exit(EXIT_FAILURE);
		}
	}
}

bool STAParser::validateFilters() const {
	// Validate all filters. if one fails, then fail the validation
	for (auto& filter: this->filters) {
		if (!validateFilter(filter)) {
			return false;
		}
	}
	return true;
}

bool STAParser::validateFilter(const STAFilter& filter) const {
	// searchs the fields information to check if this filter is
	// correctly associated with any field.
	for (auto& info: this->fieldsInfo) {
		if (info.name == filter.getFieldName()) {
			return true;
		}
	}

	// if it doen't match none of the items in fieldsInfo, then fail validation.
	return false;
}

void STAParser::parseData() {
	std::ifstream file(this->dataFilePath.c_str());

	this->outputFile.open(this->outputFilePath);

	if (file.is_open() && outputFile.is_open()) {

		writeHeader();

		for (std::string line; getline(file, line); ) {
			proccessLine(line);
		}

		file.close();
	}
}

void STAParser::writeHeader() {
	for (auto& info: this->fieldsInfo) {
		this->outputFile << "\"" << info.name << "\";";
	}
	this->outputFile << '\n';
}

void STAParser::proccessLine(const std::string& line) {
	int offset = 0;
	STARegister reg;
	for (auto& info: this->fieldsInfo) {
		int fieldLength = info.readLength();
		std::string fieldValue = line.substr(offset, fieldLength);

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
	this->outputFile << '\n';
}

void STAParser::writeField(const FieldInfo& info, const std::string& fieldValue) {
	if (info.type == 'A') {
		this->outputFile << "\"" << fieldValue << "\";";
	} else if (info.type == 'N' || info.type == 'P') {
		this->outputFile << "" << STAConverter::formatDecimal(info, fieldValue) << ";";
	} else {
		this->outputFile << "" << fieldValue << ";";
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
		std::string registerValue = reg.getValue(filter.getFieldName());

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
		std::string registerValue = reg.getValue(filter.getFieldName());

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
