#pragma once

#include "LibraryException.h"

class ResourceNotFoundException : public LibraryException {
public:
	explicit ResourceNotFoundException(const std::string& msg) : LibraryException("Resource Not Found: " + msg) {}
};