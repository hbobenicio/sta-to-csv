#ifndef STA_PARSER_H_INCLUDED
#define STA_PARSER_H_INCLUDED

#include <string>
#include <vector>
#include <map>

#include "fields.h"
#include "sta-filter.h"

class STARegister;

class STAParser {
public:
    enum MultipleFilterMode { AND, OR } ;
    
private:
    std::string refFilePath;
    std::string dataFilePath;
	std::vector<FieldInfo> fieldsInfo;
    std::vector<STAFilter> filters;
    STAParser::MultipleFilterMode multipleFilterMode;

    void parseRef();
    void parseData();

    void proccessLine(const std::string& line);

    void writeHeader();
    void writeRegister(const STARegister& reg);
    void writeField(const FieldInfo& info, const std::string& fieldValue);

    bool acceptFilter(const STARegister& reg) const;
    bool acceptFilterModeAnd(const STARegister& reg) const;
    bool acceptFilterModeOr(const STARegister& reg) const;

public:

    STAParser(const std::string& refFilePath, const std::string& dataFilePath);
    virtual ~STAParser();

    void parse();

    void addFilter(const STAFilter& filter);
    void setMultipleFilterMode(STAParser::MultipleFilterMode mode);
};

#endif