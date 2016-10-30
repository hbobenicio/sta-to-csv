#ifndef STA_CONVERTER_H_INCLUDED
#define STA_CONVERTER_H_INCLUDED

#include <string>

class FieldInfo;

class STAConverter
{
private:
    STAConverter(){}

public:
    static std::string formatDecimal(const FieldInfo& info, const std::string& value);
};

#endif
