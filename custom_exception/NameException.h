#ifndef NAME_EXCEPTION_H
#define NAME_EXCEPTION_H

#include <exception>
#include <string>

class NameException : public std::exception {
public:
	enum Reason { TOO_SHORT, TOO_LONG };

	NameException(const std::string& msg) : message(msg) {}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};

#endif