#pragma once

#include <exception>
#include <string>

class LibraryException : public std::exception {
public:
	explicit LibraryException(const std::string& msg) : message(msg) {}

	const char* what() const noexcept override {
		return message.c_str();
	}

protected:
	std::string message;
};