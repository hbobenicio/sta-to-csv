#include "sta-filter.h"

using namespace std;

STAFilter::STAFilter() {
}

STAFilter::STAFilter(const string& fieldName, STAFilterFunc comparisonFunction)
    : fieldName(fieldName), comparisonFunction(comparisonFunction)
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

string STAFilter::getFieldName() const {
    return this->fieldName;
}

STAFilterFunc STAFilter::getComparisonFunction() const {
    return this->comparisonFunction;
}
