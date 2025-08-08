#pragma once

#include <exception>

#include <string>

class AddressException : public std::exception {
public:
	AddressException(const std::string& msg = "") {
		message = "Address Exception: " + msg;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};