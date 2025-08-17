#pragma once

#include "LibraryException.h"

class DuplicateResourceException : public LibraryException {
public:
	explicit DuplicateResourceException(const std::string& msg) : LibraryException("Duplicate Resource: " + msg) {}
};