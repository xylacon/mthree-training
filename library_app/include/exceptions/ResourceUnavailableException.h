#pragma once

#include "LibraryException.h"

class ResourceUnavailableException : public LibraryException {
public:
	explicit ResourceUnavailableException(const std::string& msg = "Too many bad attempts") : LibraryException("ResourceUnavailableException: " + msg) {}
};