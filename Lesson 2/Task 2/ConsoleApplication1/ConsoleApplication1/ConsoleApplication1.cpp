#include <iostream>
#include <Windows.h>

struct BankAccount {
    int accountNumber;
    std::string holderName;
    double ballance;
};

void changeBallance(BankAccount& aBankAccount, double aNewBallance) {
    aBankAccount.ballance = aNewBallance;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);

    BankAccount bankAccount;
    std::cout << "Введите номер счета: ";
    std::cin >> bankAccount.accountNumber;
    std::cout << "Введите имя владельца: ";
    std::cin >> bankAccount.holderName;
    std::cout << "Введите баланс: ";
    std::cin >> bankAccount.ballance;

    double newBallance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBallance;

    changeBallance(bankAccount, newBallance);

    std::cout << "Ваш счет: " << bankAccount.holderName << ", " << bankAccount.accountNumber << ", " << bankAccount.ballance << std::endl;

}
