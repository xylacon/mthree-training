#pragma once

#include "Media.h"

#include <sstream>

class Video : public Media {
public:
	Video(std::string, std::string, std::string, std::string);
	Video(const int, std::string, std::string, std::string, std::string, std::stringstream&);

	std::string print_csv() const override;
	std::string print_cout() const override;

	std::unique_ptr<Media> clone() const override;

private:
	std::string videoLength;
};