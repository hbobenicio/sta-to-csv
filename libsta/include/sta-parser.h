#ifndef STA_PARSER_H_INCLUDED
#define STA_PARSER_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "fields.h"
#include "sta-filter.h"

class STARegister;

class STAParser {
public:
    enum MultipleFilterMode { AND, OR } ;

private:
    std::string refFilePath;
    std::string dataFilePath;
    std::string outputFilePath;
    std::ofstream outputFile;

    std::vector<FieldInfo> fieldsInfo;
    std::vector<STAFilter> filters;

    MultipleFilterMode multipleFilterMode {MultipleFilterMode::AND};
    bool strictConvertion {false};

    void parseRef();
    void parseData();

    void proccessLine(const std::string& line);

    void writeHeader();
    void writeRegister(const STARegister& reg);
    void writeField(const FieldInfo& info, const std::string& fieldValue);

    bool acceptFilter(const STARegister& reg) const;
    bool acceptFilterModeAnd(const STARegister& reg) const;
    bool acceptFilterModeOr(const STARegister& reg) const;

    bool validateFilters() const;
    bool validateFilter(const STAFilter& filter) const;

public:

    STAParser(const std::string& refFilePath, const std::string& dataFilePath, const std::string& outputFilePath);
    STAParser(STAParser&&) = default;
    virtual ~STAParser();

    void parse();

    void addFilter(const STAFilter& filter);
    void setMultipleFilterMode(const MultipleFilterMode& mode);
    void setStrictConvertion(bool strictFlag);
};

#endif
