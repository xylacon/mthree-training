#pragma once

#include <exception>

#include <string>

class PhoneException : public std::exception {
public:
	PhoneException(const std::string& msg = "") {
		message = "Phone Exception: " + msg;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};