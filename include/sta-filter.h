#ifndef STA_FILTER_H_INCLUDED
#define STA_FILTER_H_INCLUDED

#include <string>
#include <functional>

typedef std::function<bool(const std::string&)> STAFilterFunc;

class STAFilter
{
private:
    std::string fieldName;
    STAFilterFunc comparisonFunction;

public:
    STAFilter();
    STAFilter(const std::string& fieldName, STAFilterFunc comp);
    virtual ~STAFilter();

    // SETTERS
    void setFieldName(const std::string& fieldName);
    void setComparisonFunction(STAFilterFunc comparisonFunction);

    // GETTERS
    std::string getFieldName() const;
    STAFilterFunc getComparisonFunction() const;
};

#endif