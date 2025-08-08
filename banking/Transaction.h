#pragma once

#include <string>

class Transaction {
public:
	Transaction(const std::string& _type, const double _amount) : type(_type), amount(_amount) {}

	void display() const;
	
private:
	std::string type, date;
	double amount;
	std::string generate_date();
};