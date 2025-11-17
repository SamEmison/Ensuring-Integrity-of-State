#include <iostream>
#include "Mutable_Objects.cpp"
#include <ctime>

int main() {
    std::tm hireDate{};
    hireDate.tm_year = 124; // 2024
    hireDate.tm_mon = 0;    // January
    hireDate.tm_mday = 15;

    Employee emp("John Doe", hireDate);

    hireDate.tm_mday = 30; // Modify original
    std::tm internalDate = emp.getHireDate();
    std::cout << "Internal hire day: " << internalDate.tm_mday << " (Expected: 15)\n";

    std::tm newDate{};
    newDate.tm_year = 125; // 2025
    emp.setHireDate(newDate);
    newDate.tm_year = 126; // Modify original
    std::tm updatedDate = emp.getHireDate();
    std::cout << "Updated hire year: " << updatedDate.tm_year << " (Expected: 125)\n";

    std::cout << "Original year after modification: " << newDate.tm_year << " (Expected: 126)\n";
}
