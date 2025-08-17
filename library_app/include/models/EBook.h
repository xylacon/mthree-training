#pragma once

#include "Media.h"

#include <sstream>

class EBook : public Media {
public:
	EBook(std::string, std::string, std::string, std::string);
	EBook(const int, std::string, std::string, std::string, std::string, std::stringstream&);

	std::string print_csv() const override;
	std::string print_cout() const override;

	std::unique_ptr<Media> clone() const override;

private:
	std::string downloadSize;
};