#include "sta-filter.h"

using namespace std;

STAFilter::STAFilter() {
}

STAFilter::STAFilter(const string& fieldName, STAFilterFunc comparisonFunction)
    : fieldName(fieldName), comparisonFunction(comparisonFunction)
{

}

void STAFilter::setFieldName(const string& fieldName) {
    this->fieldName = fieldName;
}

void STAFilter::setComparisonFunction(const STAFilterFunc& comparisonFunction) {
    this->comparisonFunction = comparisonFunction;
}

const string& STAFilter::getFieldName() const {
    return this->fieldName;
}

const STAFilterFunc& STAFilter::getComparisonFunction() const {
    return this->comparisonFunction;
}
