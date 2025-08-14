#include "models/Admin.h"

#include <string>
#include <sstream>
#include <iomanip>

Admin::Admin(std::string _type, std::string _username, std::string _password, std::string _name, const double _salary) : User(_type, _username, _password, _name), salary(_salary) {}
Admin::Admin(const int _id, std::string _type, std::string _username, std::string _password, std::string _name, std::stringstream& ss) : User(_id, _type, _username, _password, _name) {
	std::string salaryStr;
	std::getline(ss, salaryStr);
	salary = std::stod(salaryStr);
}

std::string Admin::print_csv() const {
	std::ostringstream oss;
	oss << id << ','
		<< type << ','
		<< username << ','
		<< password << ','
		<< name << ','
		<< std::fixed << std::setprecision(2) << salary;
	return oss.str();
}

std::unique_ptr<User> Admin::clone() const {
	return std::make_unique<Admin>(*this);
}