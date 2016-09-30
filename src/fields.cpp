#include "fields.h"

#include <cassert>

using namespace std;

FieldInfo::FieldInfo(const string& name, char type, const string& size)
    : name(name), type(type), size(size)
{
    decimalSeparatorPos = size.find(",");
}

int FieldInfo::readLength() const {
    if (isDecimal()) {
        string x = beforeDecimalSeparator();
        string y = afterDecimalSeparator();
        return stoi(x) + stoi(y);
    } else {
        return stoi(size);
    }
}

bool FieldInfo::isDecimal() const {
    return decimalSeparatorPos != string::npos;
}

string FieldInfo::beforeDecimalSeparator() const {
    assert(isDecimal());
    return size.substr(0, decimalSeparatorPos);
}

string FieldInfo::afterDecimalSeparator() const {
    assert(isDecimal());
    return size.substr(decimalSeparatorPos + 1);
}