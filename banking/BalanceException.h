#pragma once

#include <exception>

#include <string>

class BalanceException : public std::exception {
public:
	BalanceException(const std::string& msg) : message(msg) {}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};