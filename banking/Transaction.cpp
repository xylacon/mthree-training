#include "Transaction.h"

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

void Transaction::display() const {
	std::cout
		<< date << ", "
		<< type << ", $"
		<< std::fixed << std::setprecision(2)
		<< amount << '\n';
}

std::string Transaction::generate_date() {
	std::time_t t;
	std::ostringstream ss;
	ss << std::put_time(std::localtime(&t), "%m/%d/%Y %H:%M:%S");

	return ss.str();
}