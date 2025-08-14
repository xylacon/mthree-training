#pragma once

#include "User.h"

#include <string>
#include <fstream>
#include <sstream>

class Patron : public User {
public:
	Patron(std::string, std::string, std::string, std::string, std::string);
	Patron(const int, std::string, std::string, std::string, std::string, std::stringstream&);

	std::string print_csv() const override;

	std::unique_ptr<User> clone() const override;

private:
	std::string phone;
};