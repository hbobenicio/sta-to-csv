#ifndef FIELDS_H_INCLUDED
#define FIELDS_H_INCLUDED

#include <string>

struct FieldInfo {
	std::string name;
	char type;
	std::string size;
	size_t decimalSeparatorPos;

	FieldInfo(const std::string& name, char type, const std::string& size);

	int readLength() const;
	bool isDecimal() const;

	std::string beforeDecimalSeparator() const;
	std::string afterDecimalSeparator() const;
};

#endif

