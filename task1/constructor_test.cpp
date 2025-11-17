// Test Code:
#include <iostream>
#include <stdexcept>
#include "constructor.cpp"

int main () {
  
try {
    BankAccount account1("John Doe", "123456", 1000.0, 0.05);
    std::cout << "PASS: Valid account created successfully\n";
} catch (const std::exception& e) {
    std::cout << "FAIL: " << e.what() << "\n";
}

try {
    BankAccount account2("", "123456", 1000.0, 0.05);
    std::cout << "FAIL: Empty owner was accepted\n";
} catch (const std::invalid_argument& e) {
    std::cout << "PASS: Empty owner correctly rejected - " << e.what() << "\n";
}

try {
    BankAccount account3("John Doe", "", 1000.0, 0.05);
    std::cout << "FAIL: Empty account number was accepted\n";
} catch (const std::invalid_argument& e) {
    std::cout << "PASS: Empty account number correctly rejected - " << e.what() << "\n";
}

try {
    BankAccount account4("John Doe", "123456", -100.0, 0.05);
    std::cout << "FAIL: Negative balance was accepted\n";
} catch (const std::invalid_argument& e) {
    std::cout << "PASS: Negative balance correctly rejected - " << e.what() << "\n";
}

try {
    BankAccount account5("John Doe", "123456", 1000.0, 0.15);
    std::cout << "FAIL: High interest rate was accepted\n";
} catch (const std::invalid_argument& e) {
    std::cout << "PASS: High interest rate correctly rejected - " << e.what() << "\n";
}
}
