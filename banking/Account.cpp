#include "Account.h"
#include "Transaction.h"

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

int Account::counter = 100000;

Account::Account(Client* _client, const double _balance) : id(generate_id()), dateCreated(generate_date()), balance(_balance), client(_client) {}

int Account::get_id() const {
	return id;
}

double Account::get_balance() const {
	return balance;
}

Client* Account::get_client() const {
	return client;
}

void Account::display() const {
	std::cout
		<< std::setw(6) << id << " | "
		<< std::setw(19) << dateCreated << " | "
		<< std::fixed << std::setprecision(2)
		<< std::setw(8) << balance << " | ";
	client->display();
}

void Account::display_transactions() const {
	if (transactions.empty()) {
		std::cout << "No transaction history.\n";
		return;
	}

	const size_t N = transactions.size();
	for (size_t i = 0; i < N; ++i)
		transactions[i]->display();
	std::cout << '\n';
}

void Account::make_deposit(const double amt) {
	balance += amt;
	Transaction* transaction = new Transaction("deposit", balance, amt);
	add_transaction(transaction);
}

void Account::make_withdraw(const double amt) {
	balance -= amt;
	Transaction* transaction = new Transaction("withdrawal", balance, amt);
	add_transaction(transaction);
}

void Account::add_transaction(Transaction* transaction) {
	if (transaction != nullptr)
		transactions.push_back(transaction);
}

int Account::generate_id() {
	return ++counter;
}

std::string Account::generate_date() {
	std::time_t t = std::time({});
	std::ostringstream ss;
	ss << std::put_time(std::localtime(&t), "%m/%d/%Y %H:%M:%S");

	return ss.str();
}