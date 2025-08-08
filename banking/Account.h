#pragma once

#include <string>
#include <ctime>

class Account {
public:
	Account(const double _balance) : id(generate_id()), dateCreated(generate_date()), balance(_balance) {}

	void display() const;

protected:
	int id;
	std::string dateCreated;
	double balance;

private:
	static int counter;
	int generate_id();
	std::string generate_date();
};