#include <string>
#include <iostream>

typedef double Money;
std::string balance = "string";

class Account
{
public:
    typedef std::string Money;
    Account() = default;
    ~Account() = default;

    Money GetBalance() const
    { return balance;  }

private:

    //typedef std::string Money;
    Money balance;
};

int main()
{
    Account account;
    std::cout << account.GetBalance();

    return 0;
}
