#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
private:
    string name;
    int deposit;
public:
    User(string name, int deposit);
    User(string name);
    string getName() const;
    int getDeposit() const;
    void setDeposit(int deposit);
    void depositMoney(int money);
    void withdrawMoney(int money);
};

class Bank {
private:
    vector<User> users;
public:
    bool addUser(User user);
    bool depositMoney(string name, int money);
    bool withdrawMoney(string name, int money);
    bool transferMoney(string name1, string name2, int money);
};

User::User(string name, int deposit) : name(name), deposit(deposit) {}

User::User(string name) : name(name), deposit(0) {}

string User::getName() const {
    return name;
}

int User::getDeposit() const {
    return deposit; 
}

void User::setDeposit(int deposit) {
    this->deposit = deposit;
}

void User::depositMoney(int money) {
    deposit += money;
}

void User::withdrawMoney(int money) {
    if (deposit >= money) {
        deposit -= money;
    } else {
        return;
    }
}

bool Bank::addUser(User user) {
    for (const auto& exist : users) {
        if (exist.getName() == user.getName()) {
            return false;  
        }
    }
    users.push_back(user);  
    return true;
}

bool Bank::depositMoney(string name, int money) {
    for (auto& user : users) {  
        if (user.getName() == name) {
            user.depositMoney(money);  
            return true;
        }
    }
    return false;  
}

bool Bank::withdrawMoney(string name, int money) {
    for (auto& user : users) {
        if (user.getName() == name) {
            if (user.getDeposit() >= money) {
                user.withdrawMoney(money);  
                return true;
            } else {
                return false;
            }
        }
    }
    return false;  
}

bool Bank::transferMoney(string name1, string name2, int money) {
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (auto& user : users) {
        if (user.getName() == name1) {
            user1 = &user;
        }
        if (user.getName() == name2) {
            user2 = &user;
        }
    }
    if (user1 == nullptr || user2 == nullptr|| user1 == user2) {
        return false;
    }

    if (user1->getDeposit() >= money) {
        user1->withdrawMoney(money);
        user2->depositMoney(money);
        return true;
    } else {
        return false;
    }
}
int main()
{
  User Marry("Marry",100);
  User Bruce("Bruce", 30);
  Bank bank;
  bank.addUser(Marry);
  bank.addUser(Bruce);
  cout << bank.transferMoney("Marry", "Bruce", 20)<< endl;
  cout << Marry.getDeposit() << endl;
  return 0;
}