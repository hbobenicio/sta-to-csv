#ifndef STA_FILTER_H_INCLUDED
#define STA_FILTER_H_INCLUDED

#include <string>
#include <functional>

using STAFilterFunc = std::function<bool(const std::string&)>;

class STAFilter
{
private:
    std::string fieldName;
    STAFilterFunc comparisonFunction;

public:
    STAFilter();
    STAFilter(const std::string& fieldName, STAFilterFunc comp);

    // SETTERS
    void setFieldName(const std::string& fieldName);
    void setComparisonFunction(const STAFilterFunc& comparisonFunction);

    // GETTERS
    const std::string& getFieldName() const;
    const STAFilterFunc& getComparisonFunction() const;
};

#endif
