#ifndef UNDER_AGE_EXCEPTION_H
#define UNDER_AGE_EXCEPTION_H

#include <exception>
#include <string>

class UnderAgeException : public std::exception {
public:
	UnderAgeException(const int age) {
		message = "UnderAgeException: age = " + std::to_string(age);
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};

#endif