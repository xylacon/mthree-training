#pragma once

#include <string>

class Client {
public:
	Client(const std::string& _name, const std::string& _address, const long _phone, const std::string& _email) : name(_name), address(_address), phone(std::to_string(_phone)), email(_email) {
		format_name();
		format_address();
		format_phone();
		format_email();
	}
	
	void display();

protected:
	std::string name;
	std::string address;
	std::string phone;
	std::string email;

private:
	void format_name();
	void format_address();
	void format_phone();
	void format_email();

	void remove_extra_spaces(std::string&);
	void remove_all_spaces(std::string&);
	void capitalize_words(std::string&);
	void remove_special_chars(std::string&);
	void all_lower_case(std::string&);
};