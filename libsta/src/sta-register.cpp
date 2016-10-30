#include "sta-register.h"

using namespace std;

void STARegister::addField(const FieldInfo& info, const string& value) {
    fieldsInfo.push_back(info);
    fieldsValues[info.name] = value;
}

string STARegister::getValue(const string& fieldName) const {
    return fieldsValues.at(fieldName);
}
