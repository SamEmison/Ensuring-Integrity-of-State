//Constructor File
//Sam Emison
//11/17/2025


#include <string>
#include <stdexcept>

class BankAccount {
private:
    std::string owner;
    std::string accountNumber;
    double initialBalance;
    double interestRate;
    
public:
    BankAccount(const std::string& owner, const std::string& accountNumber, 
                double initialBalance, double interestRate) 
        : owner(owner), accountNumber(accountNumber), 
          initialBalance(initialBalance), interestRate(interestRate) {

        // Rule 1: owner must not be empty
        if (owner.empty()) {
            throw std::invalid_argument("Owner name must not be empty");
        }

        // Rule 2: accountNumber must not be empty
        if (accountNumber.empty()) {
            throw std::invalid_argument("Account number must not be empty");
        }

        // Rule 3: initialBalance must be >= 0
        if (initialBalance < 0) {
            throw std::invalid_argument("Initial balance cannot be negative");
        }

        // Rule 4: interestRate must be between 0.0 and 0.1 inclusive
        if (interestRate < 0.0 || interestRate > 0.1) {
            throw std::invalid_argument("Interest rate must be between 0.0 and 0.1");
        }
    }
};

