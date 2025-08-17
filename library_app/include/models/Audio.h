#pragma once

#include "Media.h"

#include <sstream>

class Audio : public Media {
public:
	Audio(std::string, std::string, std::string, std::string);
	Audio(const int, std::string, std::string, std::string, std::string, std::stringstream&);

	std::string print_csv() const override;
	std::string print_cout() const override;

	std::unique_ptr<Media> clone() const override;

private:
	std::string audioLength;
};