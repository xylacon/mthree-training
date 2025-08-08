#pragma once

#include <string>
#include <ctime>

class Account {
public:
	Account();
	Account(const double);

protected:
	int id;
	std::string dateCreated;
	double balance;
};