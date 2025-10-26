class Bank {
private:
    vector<long long> balance;
    int n;

public:
    // Constructor
    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }

    // Helper function to check if account number is valid
    bool isValidAccount(int account) {
        return account >= 1 && account <= n;
    }

    // Withdraw money from account
    bool withdraw(int account, long long money) {
        if (!isValidAccount(account)) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }

    // Deposit money into account
    bool deposit(int account, long long money) {
        if (!isValidAccount(account)) return false;
        balance[account - 1] += money;
        return true;
    }

    // Transfer money between accounts
    bool transfer(int account1, int account2, long long money) {
        if (!isValidAccount(account1) || !isValidAccount(account2)) return false;
        if (balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
};
