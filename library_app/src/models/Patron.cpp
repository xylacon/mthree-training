#include "models/Patron.h"

#include "exceptions/InvalidResourceException.h"

Patron::Patron(std::string _type, std::string _username, std::string _password, std::string _name, std::string _phone) : User(_type, _username, _password, _name), phone(_phone) {
	if (_type != "patron")
        throw InvalidResourceException("Creating Patron object of type \"" + _type + "\" is not allowed");
}
Patron::Patron(const int _id, std::string _type,  std::string _username, std::string _password, std::string _name, std::stringstream& ss) : User(_id, _type, _username, _password, _name) {
	if (_type != "patron")
        throw InvalidResourceException("Creating Patron object of type \"" + _type + "\" is not allowed");
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