#include "Account.h"
#include "Transaction.h"

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

int Account::counter = 100000;

void Account::display() const {
	std::cout
		<< "Account Information:\n"
		<< "Account ID: " << id << '\n'
		<< "Date Created: " << dateCreated << '\n'
		<< std::fixed << std::setprecision(2)
		<< "Current Balance: " << balance << "\n\n";
	client->display();
	std::cout << '\n';
}

void Account::display_transactions() const {
	const size_t N = transactions.size();

	std::cout << "Transactions:\n";
	for (size_t i = 0; i < N; ++i) {
		std::cout << "Transaction " << i+1 << ": ";
		transactions[i]->display();
	}
	std::cout << '\n';
}

int Account::generate_id() {
	return ++counter;
}

std::string Account::generate_date() {
	std::time_t t;
	std::ostringstream ss;
	ss << std::put_time(std::localtime(&t), "%m/%d/%Y %H:%M:%S");

	return ss.str();
}