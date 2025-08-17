#pragma once

#include "LibraryException.h"

class InvalidUserException : public LibraryException {
public:
	explicit InvalidUserException(const std::string& msg) : LibraryException("InvalidUserException: ") {}
};