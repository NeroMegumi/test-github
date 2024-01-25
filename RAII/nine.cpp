#include <iostream>
#include <string>

using namespace std;

class Transaction {
public:
    explicit Transaction(const std::string& logInfo);
    void LogTransaction(const std::string& logInfo) const;
};

Transaction::Transaction(const std::string& logInfo) {
    LogTransaction(logInfo);
}

void Transaction::LogTransaction(const std::string& logInfo) const {
    cout << "Transaction Log: " << logInfo << endl;
}

class BuyTransaction : public Transaction {
public:
    BuyTransaction(const std::string& logInfo)
        : Transaction(CreateLogString(logInfo)) {
            cout << logInfo << endl;
        }

private:
    static std::string CreateLogString(const std::string& logInfo);
};

std::string BuyTransaction::CreateLogString(const std::string& logInfo) {
    return "Buy Transaction Log: " + logInfo;
}

int main() {
    BuyTransaction b("Hello, world!");
    BuyTransaction b("Test Branch function");
    return 0;
}
