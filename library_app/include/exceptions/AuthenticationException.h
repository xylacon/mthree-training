#pragma once

#include "LibraryException.h"

class AuthenticationException : public LibraryException {
public:
	explicit AuthenticationException(const std::string& msg = "Too many bad attempts") : LibraryException("AuthenticationException: " + msg) {}
};