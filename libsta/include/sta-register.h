#ifndef STA_REGISTER_H_INCLUDED
#define STA_REGISTER_H_INCLUDED

#include <vector>
#include <unordered_map>
#include <string>

#include "fields.h"

struct STARegister
{
    std::unordered_map<std::string, std::string> fieldsValues;
    std::vector<FieldInfo> fieldsInfo;

    void addField(const FieldInfo& info, const std::string& value);
    std::string getValue(const std::string& fieldName) const;
};

#endif
