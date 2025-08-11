#include "Client.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

void Client::display() {
	std::cout
		<< std::setw(30) << std::left << name << " | "
		<< std::setw(30) << std::left << address << " | "
		<< std::setw(13) << std::left << phone << " | "
		<< std::setw(30) << std::left << email << '\n';
}

void Client::format_name() {
	remove_extra_spaces(name);
	remove_special_chars(name);
	capitalize_words(name);
}

void Client::format_address() {
	remove_extra_spaces(address);
	capitalize_words(address);
}

void Client::format_phone() {
	phone = "(" + phone.substr(0, 3) + ")" + phone.substr(3, 3) + "-" + phone.substr(6);
}

void Client::format_email() {
	remove_all_spaces(email);
	all_lower_case(email);
}

void Client::remove_extra_spaces(std::string& str) {
	auto it = str.begin();
	while (it != str.end()) {
		// Find first space
		while (it != str.end() && !std::isspace(*it)) ++it;

		if (it != str.end())
			++it;

		while (it != str.end() && std::isspace(*it)) it = str.erase(it);
	}
}

void Client::remove_all_spaces(std::string& str) {
	auto it = str.begin();
	while (it != str.end()) {
		if (std::isspace(*it))
			it = str.erase(it);
		else
			++it;
	}
}

void Client::capitalize_words(std::string& str) {
	auto it = str.begin();
	while (it != str.end()) {
		// Find first letter
		while (it != str.end() && std::isspace(*it)) ++it;

		if (it != str.end() && std::isalpha(*it))
			*it = std::toupper(*it);
		
		++it;

		// Find next space
		while (it != str.end() && !std::isspace(*it)) ++it;
	}
}

void Client::remove_special_chars(std::string& str) {
	auto it = str.begin();
	while (it != str.end()) {
		if (std::isalnum(*it) || std::isspace(*it))
			++it;
		else
			it = str.erase(it);
	}
}

void Client::all_lower_case(std::string& str) {
	auto it = str.begin();
	while (it != str.end()) {
		if (std::isalpha(*it))
			*it = std::tolower(*it);
		++it;
	}
}