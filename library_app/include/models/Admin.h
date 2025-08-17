#pragma once

#include "User.h"

#include <sstream>

class Admin : public User {
public:
	Admin(std::string, std::string, std::string, std::string, const double);
	Admin(const int, std::string, std::string, std::string, std::string, std::stringstream&);

	std::string print_csv() const override;

	std::unique_ptr<User> clone() const override;

private:
	double salary;
};