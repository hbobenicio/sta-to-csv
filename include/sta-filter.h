#ifndef STA_FILTER_H_INCLUDED
#define STA_FILTER_H_INCLUDED

#include <string>
#include <memory>
#include <functional>

typedef std::function<bool(const std::string&, const std::string&)> STAFilterFunc;

class STAFilter
{
private:
    std::string fieldName;
    STAFilterFunc comparisonFunction;
    std::string value;

public:
    STAFilter();
    STAFilter(const std::string& fieldName, STAFilterFunc comp, const std::string& value);
    virtual ~STAFilter();

    void setFieldName(const std::string& fieldName);
    void setComparisonFunction(STAFilterFunc comparisonFunction);
    void setValue(const std::string& value);

    std::string getFieldName() const;
    STAFilterFunc getComparisonFunction() const;
    std::string getValue() const;
};

#endif