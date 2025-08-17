#pragma once

#include "LibraryException.h"

class BadOperationException : public LibraryException {
public:
	explicit BadOperationException(const std::string& msg = "Too many bad attempts") : LibraryException("BadOperationException: " + msg) {}
};