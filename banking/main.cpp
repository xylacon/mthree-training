#include "Account.h"
#include "CurrentAccount.h"
#include "SalaryAccount.h"
#include "SavingsAccount.h"

#include "Client.h"
#include "Business.h"
#include "Employee.h"
#include "Individual.h"

#include "BalanceException.h"
#include "NameException.h"
#include "PhoneException.h"
#include "AddressException.h"
#include "EmailException.h"

#include <iostream>
#include <string>
#include <cctype>

Account* createAccount();
CurrentAccount* createCurrentAccount();
SalaryAccount* createSalaryAccount();
SavingsAccount* createSavingsAccount();

void getClientInfo(std::string&, std::string&, long&, std::string&, const std::string&);

bool isValidName(const std::string&);
bool isValidAddress(const std::string&);
bool isValidPhone(std::string&);
bool isValidEmail(const std::string&);
bool isValidBalance(const double);

int main() {
	Account* account = createAccount();
	if (account == nullptr) {
		std::cout << "Account creation failed.\n";
		return 1;
	}

	account->display();

	/*
		TO-DO:
		- Deposit money
		- Withdraw money
		- Account information
		- Transaction history
	*/

	return 0;
}

Account* createAccount() {
	std::cout
		<< "CREATE NEW ACCOUNT\n"
		<< "1. Individual\n"
		<< "2. Employee\n"
		<< "3. Business\n"
		<< "Choose an option: ";
	int choice;
	std::cin >> choice;
	std::cin.ignore();
	std::cout << '\n';

	Account* account;
	switch (choice) {
		case 1:
			account = createSavingsAccount();
			break;
		case 2:
			account = createSalaryAccount();
			break;
		case 3:
			account = createCurrentAccount();
			break;
		default:
			std::cout << "Invalid choice.\n";
			return nullptr;
	}
	std::cout << '\n';

	return account;
}
CurrentAccount* createCurrentAccount() {
	std::cout << "Creating a current account...\n";
	
	std::string name, address, email;
	long phone = -1;
	getClientInfo(name, address, phone, email, "Business");
	if (name.empty() || address.empty() || phone == -1 || email.empty())
		return nullptr;

	try {
		std::cout << "Enter initial balance: ";
		double balance;
		std::cin >> balance;

		if (!isValidBalance(balance))
			throw BalanceException();

		Business* client = new Business(name, address, phone, email);
		CurrentAccount* account = new CurrentAccount(client, balance);

		return account;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return nullptr;
}
SalaryAccount* createSalaryAccount() {

	return nullptr;
}
SavingsAccount* createSavingsAccount() {

	return nullptr;
}

void getClientInfo(std::string& name, std::string& address, long& phone, std::string& email, const std::string& type) {
	try {
		std::cout << "Enter " << type << " name: ";
		std::getline(std::cin, name);
		if (!isValidName(name))
			throw NameException();

		std::cout << "Enter " << type << " address: ";
		std::getline(std::cin, address);
		if (!isValidAddress(address))
			throw AddressException();

		std::cout << "Enter " << type << " phone: ";
		std::string _phone;
		std::getline(std::cin, _phone);
		if (isValidPhone(_phone))
			phone = stol(_phone);
		else
			throw PhoneException();

		std::cout << "Enter " << type << " email: ";
		std::getline(std::cin, email);
		if (!isValidEmail(email))
			throw EmailException();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

bool isValidName(const std::string& name) {
	return name.size() >= 5 && name.size() <= 30;
}

bool isValidAddress(const std::string& address) {
	auto it = address.begin();
	while (it != address.end()) {
		if (std::isdigit(*it))
			return true;
		++it;
	}

	return false;
}

bool isValidPhone(std::string& phone) {
	auto it = phone.begin();
	while (it != phone.end()) {
		if (!std::isdigit(*it))
			it = phone.erase(it);
		else
			++it;
	}

	return phone.size() == 10;
}

bool isValidEmail(const std::string& email) {
	auto it = email.begin();
	int at = 0;
	bool hasDotAfterAt = false;
	
	if (*it++ == '.' || *it == '@') return false;

	while (it != email.end()) {
		if (*it == '@')
			++at;
		if (*it == '.' && at > 0)
			hasDotAfterAt = true;
		++it;
	}

	return at == 1 && hasDotAfterAt;
}


bool isValidBalance(const double balance) {
	return balance >= 500.00 && balance <= 50000.00;
}
