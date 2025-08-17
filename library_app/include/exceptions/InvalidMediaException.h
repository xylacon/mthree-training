#pragma once

#include "LibraryException.h"

class InvalidMediaException : public LibraryException {
public:
	explicit InvalidMediaException(const std::string& msg) : LibraryException("InvalidMediaException: ") {}
};