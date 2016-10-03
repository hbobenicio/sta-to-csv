#include "sta-filter.h"

STAFilter(const std::string& fieldName, const STAComparator& comp, const std::string& value)
    : fieldName(fieldName), comparisonFunction(comp), value(value)
{

}

STAFilter::~STAFilter()
{

}
