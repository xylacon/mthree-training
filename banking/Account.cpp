#include "Account.h"

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
		<< "Current Balance: " << balance << '\n';
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