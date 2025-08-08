#pragma once

#include <exception>

#include <string>

class NameException : public std::exception {
public:
	NameException(const std::string& msg = "") {
		message = "Name Exception: " + msg;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};