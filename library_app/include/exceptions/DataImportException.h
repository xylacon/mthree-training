#pragma once

#include "LibraryException.h"

class DataImportException : public LibraryException {
public:
	explicit DataImportException(const std::string& msg = "Failed to import data") : LibraryException("DataImportException: " + msg) {}
};