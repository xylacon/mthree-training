#pragma once

#include "Media.h"

#include <string>
#include <fstream>
#include <sstream>

class Book : public Media {
public:
	Book(std::string, std::string, std::string, std::string, std::string);
	Book(const int, std::string, std::string, std::string, std::string, std::stringstream&);

	std::string print_csv() const override;

	std::unique_ptr<Media> clone() const override;

private:
	std::string coverType;
};