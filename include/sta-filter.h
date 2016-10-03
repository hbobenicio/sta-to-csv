#ifndef STA_FILTER_H_INCLUDED
#define STA_FILTER_H_INCLUDED

#include <functional>
#include <string>

typedef std::binary_function<const std::string&, const std::string&, bool> STAComparator;

struct Eq : public STAComparator {
    bool operator() (const std::string& a, const std::string& b) {
        return a == b;
    }
};

class STAFilter
{
private:
    std::string fieldName;
    STAComparator comparisonFunction;
    std::string value;

public:
    STAFilter(const std::string& fieldName, const STAComparator& comp, const std::string& value);
    virtual ~STAFilter();

};

#endif