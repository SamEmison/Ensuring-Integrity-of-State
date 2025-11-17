//Invariant Checking
//Sam Emison
//11/17/2025

#include <string>
#include <memory>
#include <stdexcept>

class Account {
private:
    std::string accountNumber;
    double creditLimit = -1.0;
    std::shared_ptr<Account> fallbackAccount = nullptr;

public:
    Account(const std::string& accountNumber) : accountNumber(accountNumber) {}

    void setCreditLimit(double creditLimit) {
        this->creditLimit = creditLimit;
        checkInvariants();
    }

    void setFallbackAccount(std::shared_ptr<Account> fallbackAccount) {
        this->fallbackAccount = fallbackAccount;
        checkInvariants();
    }

private:
    void checkInvariants() {
        bool hasCreditLimit = (creditLimit >= 0);
        bool hasFallback = (fallbackAccount != nullptr);

        if ((hasCreditLimit && hasFallback) || (!hasCreditLimit && !hasFallback)) {
            throw std::logic_error("Invariant violation");
        }
    }
};
