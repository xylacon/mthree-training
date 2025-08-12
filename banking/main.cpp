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
#include <vector>
#include <cctype>
#include <iomanip>
#include <stdexcept>

void run(std::vector<Account*>);
void runAuth(Account*);
void printMenu();
void printMenuAuth();

void printAccount(Account*);
void printTransactions(Account*);

Account* createAccount();
CurrentAccount* createCurrentAccount();
SalaryAccount* createSalaryAccount();
SavingsAccount* createSavingsAccount();

Account* signIn(std::vector<Account*>);

void makeDeposit(Account*);
void makeWithdrawal(Account*);

void getClientInfo(std::string&, std::string&, long&, std::string&, const std::string&);

bool isValidName(const std::string&);
bool isValidAddress(const std::string&);
bool isValidPhone(std::string&);
bool isValidEmail(const std::string&);

int main() {
	std::vector<Account*> accounts;

	// id = 100001
	Individual* client1 = new Individual("Richard Denton", "123 Abc Ln", 1234567890, "richard.denton@email.com");
	SavingsAccount* account1 = new SavingsAccount(client1, 2000.00);
	accounts.push_back(account1);
	account1->deposit(350.00);
	account1->withdraw(670.00);
	account1->withdraw(5000.00);
	account1->withdraw(400.00);
	account1->deposit(230.00);

	// id = 100002
	Employee* client2 = new Employee("John Doe", "5532 Doey Pkwy, Dallas, TX 77098", 9948837612, "doey.joey@email.com");
	SalaryAccount* account2 = new SalaryAccount(client2, 4500.00);
	accounts.push_back(account2);
	account2->deposit(500.00);
	account2->deposit(500.00);
	account2->withdraw(670.00);
	account2->deposit(100000.00);
	account2->withdraw(80.00);

	// id = 100003
	Employee* client3 = new Employee("Fake Company", "531 Street St, Buffalo, NY 98241", 1010101010, "admin@fakecompany.com");
	SalaryAccount* account3 = new SalaryAccount(client3, 10000.00);
	accounts.push_back(account3);
	account3->deposit(5000.00);
	account3->deposit(20000.00);
	account3->withdraw(8000.00);
	account3->withdraw(12000.00);
	account3->deposit(50000.00);

	run(accounts);

	return 0;
}

void run(std::vector<Account*> accounts) {
	std::cout << "Welcome to Denton Bank\n\n";

	int choice;
	while (true) {
		printMenu();

		while (true) {
			std::cout << "Choose an option: ";
			std::cin >> choice;

			if (choice < 1 || choice > 3)
				std::cout << "Invalid choice.\n";
			else
				break;
		}
		std::cout << '\n';

		if (choice == 3) {
			std::cout << "Goodbye.\n";
			break;
		}

		Account* account;
		switch (choice) {
			case 1:
				account = createAccount();
				if (account == nullptr)
					std::cout << "Account creation failed.\n";
				else {
					accounts.push_back(account);
					std::cout<< "Account successfully created:\n\n";
					printAccount(account);
					std::cout << '\n';
					std::cout << "Welcome " << account->get_client()->get_name() << "!\n";
					runAuth(account);
				}
				break;
			case 2:
				account = signIn(accounts);
				if (account == nullptr)
					std::cout << "Account not found.\n";
				else {
					std::cout << "Welcome " << account->get_client()->get_name() << "!\n";
					runAuth(account);
				}
				break;
			default:
				std::cout << "ERROR: Bad choice.\n";
		}
	}
}

void runAuth(Account* account) {
	int choice;
	while (true) {
		printMenuAuth();

		while (true) {
			std::cout << "Choose an option: ";
			std::cin >> choice;

			if (choice < 1 || choice > 5)
				std::cout << "Invalid choice.\n";
			else
				break;
		}
		std::cout << '\n';

		if (choice == 5) {
			std::cout << "Signed out.\n";
			break;
		}

		switch (choice) {
			case 1:
				makeDeposit(account);
				break;
			case 2:
				makeWithdrawal(account);
				break;
			case 3:
				printAccount(account);
				break;
			case 4:
				printTransactions(account);
				break;
			default:
				std::cout << "ERROR: Bad choice.\n";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void printMenu() {
	std::cout
		<< "1. Create an account\n"
		<< "2. Sign in\n"
		<< "3. Quit\n";
}

void printMenuAuth() {
	std::cout
		<< "1. Deposit\n"
		<< "2. Withdraw\n"
		<< "3. Display account info\n"
		<< "4. Display transactions\n"
		<< "5. Sign out\n";
}

void printAccount(Account* account) {
	std::cout
		<< std::setw(6) << std::left << "ID" << " | "
		<< std::setw(19) << std::left << "Date created" << " | "
		<< std::setw(8) << std::left << "Balance" << " | ";
	std::cout
		<< std::setw(30) << std::left << "Name" << " | "
		<< std::setw(40) << std::left << "Address" << " | "
		<< std::setw(13) << std::left << "Phone" << " | "
		<< std::setw(30) << std::left << "Email" << '\n';
	std::cout << std::setw(164) << std::setfill('-') << "" << '\n' << std::setfill(' ');

	account->display();
}

void printTransactions(Account* account) {
	std::cout << "TRANSACTIONS\n";
	std::cout
		<< std::setw(19) << std::left << "Date" << " | "
		<< std::setw(10) << std::left << "Type" << " | "
		<< std::setw(8) << std::left << "Amount" << " | "
		<< std::setw(8) << std::left << "Balance" << '\n';
		std::cout << std::setw(53) << std::setfill('-') << "" << '\n' << std::setfill(' ');

	account->display_transactions();
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
	std::cout << "Creating a current account\n";
	
	std::string name, address, email;
	long phone = -1;
	getClientInfo(name, address, phone, email, "Business");
	if (name.empty() || address.empty() || phone == -1 || email.empty())
		return nullptr;

	try {
		std::cout << "Enter initial balance: ";
		double balance;
		std::cin >> balance;

		if (balance < CurrentAccount::MIN_BALANCE || balance > CurrentAccount::MAX_BALANCE)
			throw BalanceException("out of bounds");

		Business* client = new Business(name, address, phone, email);
		if (client == nullptr)
			throw std::runtime_error("Failed to create new client");

		CurrentAccount* account = new CurrentAccount(client, balance);

		return account;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return nullptr;
}
SalaryAccount* createSalaryAccount() {
	std::cout << "Creating a salary account\n";
	
	std::string name, address, email;
	long phone = -1;
	getClientInfo(name, address, phone, email, "Employee");
	if (name.empty() || address.empty() || phone == -1 || email.empty())
		return nullptr;

	try {
		std::cout << "Enter initial balance: ";
		double balance;
		std::cin >> balance;

		if (balance < SalaryAccount::MIN_BALANCE || balance > SalaryAccount::MAX_BALANCE)
			throw BalanceException("out of bounds");

		Employee* client = new Employee(name, address, phone, email);
		if (client == nullptr)
			throw std::runtime_error("Failed to create new client");

		SalaryAccount* account = new SalaryAccount(client, balance);

		return account;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return nullptr;
}
SavingsAccount* createSavingsAccount() {
	std::cout << "Creating a savings account\n";
	
	std::string name, address, email;
	long phone = -1;
	getClientInfo(name, address, phone, email, "Individual");
	if (name.empty() || address.empty() || phone == -1 || email.empty())
		return nullptr;

	try {
		std::cout << "Enter initial balance: ";
		double balance;
		std::cin >> balance;

		if (balance < SavingsAccount::MIN_BALANCE || balance > SavingsAccount::MAX_BALANCE)
			throw BalanceException("out of bounds");

		Individual* client = new Individual(name, address, phone, email);
		if (client == nullptr)
			throw std::runtime_error("Failed to create new client");

		SavingsAccount* account = new SavingsAccount(client, balance);

		return account;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return nullptr;
}

Account* signIn(std::vector<Account*> accounts) {
	std::cout << "Enter your account ID: ";
	int id;
	std::cin >> id;

	for (const auto& a : accounts)
		if (a->get_id() == id)
			return a;
	
	return nullptr;
}

void makeDeposit(Account* account) {
	if (account == nullptr) {
		std::cout << "Account does not exist.\n";
		return;
	}

	std::cout
		<< "MAKE DEPOSIT\n"
		<< "Current balance: " << std::fixed << std::setprecision(2) << account->get_balance() << '\n'
		<< "Enter deposit amount: ";
	double deposit;
	std::cin >> deposit;
	std::cout << '\n';

	if (account->deposit(deposit))
		std::cout << "Deposit successful. New balance: " << std::fixed << std::setprecision(2) << account->get_balance() << '\n';
	else
		std::cout << "Deposit failed.\n";
}
void makeWithdrawal(Account* account) {
	if (account == nullptr) {
		std::cout << "Account does not exist.\n";
		return;
	}

	std::cout
		<< "MAKE WITHDRAWAL\n"
		<< "Current balance: " << std::fixed << std::setprecision(2) << account->get_balance() << '\n'
		<< "Enter withdrawal amount: ";
	double withdrawal;
	std::cin >> withdrawal;
	std::cout << '\n';

	if (account->withdraw(withdrawal))
		std::cout << "Withdrawal successful. New balance: " << std::fixed << std::setprecision(2) << account->get_balance() << '\n';
	else
		std::cout << "Withdrawal failed.\n";
}

void getClientInfo(std::string& name, std::string& address, long& phone, std::string& email, const std::string& type) {
	try {
		std::cout << "Enter " << type << " name: ";
		std::getline(std::cin, name);
		if (name.size() < 5)
			throw NameException("too short");
		else if (name.size() > 30)
			throw NameException("too long");

		std::cout << "Enter " << type << " address: ";
		std::getline(std::cin, address);
		if (!isValidAddress(address))
			throw AddressException("Invalid");

		std::cout << "Enter " << type << " phone: ";
		std::string _phone;
		std::getline(std::cin, _phone);
		if (isValidPhone(_phone))
			phone = stol(_phone);
		else
			throw PhoneException("Invalid");

		std::cout << "Enter " << type << " email: ";
		std::getline(std::cin, email);
		if (!isValidEmail(email))
			throw EmailException("Invalid");
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
