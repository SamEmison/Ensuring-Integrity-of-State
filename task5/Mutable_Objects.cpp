//Mutable Objects
//Sam Emison
//11/17/2025

#include <string>
#include <ctime>

class Employee {
private:
    std::string name;
    std::tm hireDate;

    std::tm copyTm(const std::tm& source) const {
        std::tm copy = source;
        return copy;
    }

public:
    Employee(const std::string& name, const std::tm& hireDate) 
        : name(name), hireDate(copyTm(hireDate)) {}

    std::tm getHireDate() const {
        return copyTm(hireDate);
    }

    void setHireDate(const std::tm& newHireDate) {
        hireDate = copyTm(newHireDate);
    }
};
