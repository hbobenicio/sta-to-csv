#include "sta-converter.h"

#include <string>
#include "fields.h"

using namespace std;

string STAConverter::formatDecimal(const FieldInfo& info, const string& value) {
    string response = value;
    if (info.isDecimal()) {
        int pos = stoi(info.beforeDecimalSeparator());
        response.insert(pos, ",");
    }
    return response;
}
