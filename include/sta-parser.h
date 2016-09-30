#ifndef STA_PARSER_H_INCLUDED
#define STA_PARSER_H_INCLUDED

#include <string>
#include <vector>
#include <map>

#include "fields.h"

class STARegister;

class STAParser {
private:
    std::string refFilePath;
    std::string dataFilePath;
	std::vector<FieldInfo> fieldsInfo;

    void parseRef();
    void parseData();
    void proccessLine(const std::string& line);
    void writeHeader();
    void writeField(const FieldInfo& info, const std::string& fieldValue);
    void writeRegister(const STARegister& reg);

public:

    STAParser(const std::string& refFilePath, const std::string& dataFilePath);
    virtual ~STAParser();

    void parse();
};

#endif