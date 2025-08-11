#include "Transaction.h"

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

Transaction::Transaction(const std::string& _type = "null", const double _balance = 0.0, const double _amount = 0.0) : type(_type), balance(_balance), amount(_amount) {}

void Transaction::display() const {
	std::cout
		<< std::setw(19) << date << " | "
		<< std::setw(10) << std::left << type << " | "
		<< std::fixed << std::setprecision(2)
		<< std::setw(8) << amount << " | "
		<< std::setw(8) << balance << '\n';
}

std::string Transaction::generate_date() {
	std::time_t t = std::time({});
	std::ostringstream ss;
	ss << std::put_time(std::localtime(&t), "%m/%d/%Y %H:%M:%S");

	return ss.str();
}