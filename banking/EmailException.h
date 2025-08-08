#pragma once

#include <exception>

#include <string>

class EmailException : public std::exception {
public:
	EmailException(const std::string& msg = "") {
		message = "Email Exception: " + msg;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};