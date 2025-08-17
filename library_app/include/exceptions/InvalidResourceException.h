#pragma once

#include "LibraryException.h"

class InvalidResourceException : public LibraryException {
public:
	explicit InvalidResourceException(const std::string& msg) : LibraryException("InvalidResourceException: " + msg) {}
};