#ifndef LOWER_LENGTH_OF_CHARACTERS_H
#define LOWER_LENGTH_OF_CHARACTERS_H

#include <exception>
#include <string>

class LowerLengthOfCharacters : public std::exception {
public:
	LowerLengthOfCharacters(const int length) {
		message = "LowerLengthOfCharacters: length = " + std::to_string(length);
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	std::string message;
};

#endif