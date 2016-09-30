#include "fields.h"

#include <cassert>

FieldInfo::FieldInfo(const std::string& name, char type, const std::string& size)
    : name(name), type(type), size(size)
{
    decimalSeparatorPos = size.find(",");
}

int FieldInfo::readLength() const {
    if (isDecimal()) {
        std::string x = beforeDecimalSeparator();
        std::string y = afterDecimalSeparator();
        return std::stoi(x) + std::stoi(y);
    } else {
        return std::stoi(size);
    }
}

bool FieldInfo::isDecimal() const {
    return decimalSeparatorPos != std::string::npos;
}

std::string FieldInfo::beforeDecimalSeparator() const {
    assert(isDecimal());
    return size.substr(0, decimalSeparatorPos);
}

std::string FieldInfo::afterDecimalSeparator() const {
    assert(isDecimal());
    return size.substr(decimalSeparatorPos + 1);
}