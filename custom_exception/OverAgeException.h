#ifndef OVER_AGE_EXCEPTION_H
#define OVER_AGE_EXCEPTION_H

#include <exception>
#include <string>

class OverAgeException : public std::exception {
public:
	OverAgeException(const int age) {
		message = "OverAgeException: age = " + std::to_string(age);
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};

#endif