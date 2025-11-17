#include <iostream>
#include <memory>
#include "Invariant_Checking.cpp"

int main() {
    try {
        Account acc1("ACC001");
        acc1.setCreditLimit(5000.0);
        std::cout << "PASS: Credit limit only account created\n";
    } catch (const std::exception& e) {
        std::cout << "FAIL: " << e.what() << "\n";
    }

    try {
        Account acc2("ACC002");
        acc2.setFallbackAccount(std::make_shared<Account>("ACC003"));
        std::cout << "PASS: Fallback account only created\n";
    } catch (const std::exception& e) {
        std::cout << "FAIL: " << e.what() << "\n";
    }

    try {
        Account acc3("ACC004");
        acc3.setCreditLimit(5000.0);
        acc3.setFallbackAccount(std::make_shared<Account>("ACC005"));
        std::cout << "FAIL: Both credit and fallback were accepted\n";
    } catch (const std::logic_error& e) {
        std::cout << "PASS: Both credit and fallback correctly rejected - " << e.what() << "\n";
    }

    try {
        Account acc4("ACC006");
        acc4.setCreditLimit(-1.0);
        std::cout << "FAIL: No credit or fallback was accepted\n";
    } catch (const std::logic_error& e) {
        std::cout << "PASS: No credit or fallback correctly rejected - " << e.what() << "\n";
    }
}
