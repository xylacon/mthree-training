#include "models/Patron.h"

#include <string>
#include <sstream>

Patron::Patron(std::string _type, std::string _username, std::string _password, std::string _name, std::string _phone) : User(_type, _username, _password, _name), phone(_phone) {}
Patron::Patron(const int _id, std::string _type,  std::string _username, std::string _password, std::string _name, std::stringstream& ss) : User(_id, _type, _username, _password, _name) {
	std::getline(ss, phone);
}

std::string Patron::print_csv() const {
	std::ostringstream oss;
	oss << id << ','
		<< type << ','
		<< username << ','
		<< password << ','
		<< name << ','
		<< phone;
	return oss.str();
}

std::unique_ptr<User> Patron::clone() const {
	return std::make_unique<Patron>(*this);
}