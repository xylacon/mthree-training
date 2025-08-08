#include "Account.h"
#include "CurrentAccount.h"
#include "SalaryAccount.h"
#include "SavingsAccount.h"

#include "Client.h"

#include <iostream>
#include <string>

Account* createAccount();
CurrentAccount* createCurrentAccount();
SalaryAccount* createSalaryAccount();
SavingsAccount* createSavingsAccount();

bool isValidName(const std::string&);
bool isValidBalance(const double);

int main() {
	// ACCOUNT
	// std::cout << "Enter balance: ";
	// double balance;
	// std::cin >> balance;
	// std::cout << '\n';

	// Account account(balance);
	// account.display();

	// CLIENT
	// std::cout << "Enter name: ";
	// std::string name;
	// std::getline(std::cin, name);

	// std::cout << "Enter address: ";
	// std::string address;
	// std::getline(std::cin, address);

	// std::cout << "Enter phone: ";
	// int phone;
	// std::cin >> phone;

	// std::cout << "Enter email: ";
	// std::cin.ignore();
	// std::string email;
	// std::getline(std::cin, email);
	// std::cout << '\n';

	// Client client(name, address, phone, email);
	// client.display();


	// CREATE ACCOUNT
	// Choose an account type (current, salary, savings)
	// Get account deposit
	// Get client information

	// 
}

Account* createAccount() {
	std::cout
		<< "CREATE NEW ACCOUNT\n\n"
		<< "1. Individual\n"
		<< "2. Employee\n"
		<< "3. Business\n"
		<< "Choose an option: ";
	int choice;
	std::cin >> choice;

	Account* account;
	switch (choice) {
		case 1:
			account = createCurrentAccount();
			break;
		case 2:
			account = createSalaryAccount();
			break;
		case 3:
			account = createSavingsAccount();
			break;
		default:
			std::cout << "Invalid choice.\n";
			return nullptr;
	}


}
CurrentAccount* createCurrentAccount() {

}
SalaryAccount* createSalaryAccount() {

}
SavingsAccount* createSavingsAccount() {

}

bool isValidName(const std::string& name) {
	return name.size() >= 5 && name.size() <= 30;
}

bool isValidBalance(const double balance) {
	return balance >= 500.00 && balance <= 50000.00;
}
