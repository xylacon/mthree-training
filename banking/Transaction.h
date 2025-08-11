#pragma once

#include <string>

class Transaction {
public:
	Transaction(const std::string&, const double, const double);

	void display() const;
	
private:
	std::string type, date;
	double balance, amount;
	std::string generate_date();
};