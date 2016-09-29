#ifndef FIELDS_H_INCLUDED
#define FIELDS_H_INCLUDED

#include <string>

struct FieldInfo {
	std::string name;
	char type;
	std::string size;

	int readLength() const {
		size_t pos = size.find(",");
		if (pos == std::string::npos) {
			return std::stoi(size);
		} else {
			std::string x = size.substr(0, pos);
			std::string y = size.substr(pos+1);
			return std::stoi(x) + std::stoi(y);
		}
	}
};

#endif

