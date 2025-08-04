#ifndef HIGHER_LENGTH_OF_CHARACTERS_H
#define HIGHER_LENGTH_OF_CHARACTERS_H

#include <exception>
#include <string>

class HigherLengthOfCharacters : public std::exception {
public:
	HigherLengthOfCharacters(const int length) {
		message = "HigherLengthOfCharacters: length = " + std::to_string(length);
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};

#endif