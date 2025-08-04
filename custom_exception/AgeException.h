#ifndef AGE_EXCEPTION_H
#define AGE_EXCEPTION_H

#include <exception>
#include <string>

class AgeException : public std::exception {
public:
	AgeException(const std::string& msg) : message(msg) {}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};

#endif