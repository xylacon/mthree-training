#include "models/User.h"

#include "utility.h"

int User::counter = 0;

User::User(std::string _type, std::string _username, std::string _password, std::string _name) : id(utils::generate_id(counter)), type(_type), username(_username), password(_password), name(_name) {}
User::User(const int _id, std::string _type, std::string _username, std::string _password, std::string _name) : id(_id), type(_type), username(_username), password(_password), name(_name) {
	if (_id > counter)
		counter = _id;
}

int User::get_id() const { return id; }
std::string User::get_type() const { return type; }
std::string User::get_username() const { return username; }
std::string User::get_password() const { return password; }
std::string User::get_name() const { return name; }