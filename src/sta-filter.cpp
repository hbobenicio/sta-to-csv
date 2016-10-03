#include "sta-filter.h"

using namespace std;

STAFilter::STAFilter() {
}

STAFilter::STAFilter(const string& fieldName, STAFilterFunc comparisonFunction, const string& value)
    : fieldName(fieldName), comparisonFunction(comparisonFunction), value(value)
{

}

STAFilter::~STAFilter() {
}

void STAFilter::setFieldName(const string& fieldName) {
    this->fieldName = fieldName;
}

void STAFilter::setComparisonFunction(STAFilterFunc comparisonFunction) {
    this->comparisonFunction = comparisonFunction;
}

void STAFilter::setValue(const string& value) {
    this->value = value;
}

string STAFilter::getFieldName() const {
    return fieldName;
}

STAFilterFunc STAFilter::getComparisonFunction() const {
    return comparisonFunction;
}

string STAFilter::getValue() const {
    return value;
}
