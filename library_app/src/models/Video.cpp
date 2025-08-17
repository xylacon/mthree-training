#include "models/Video.h"

#include "exceptions/InvalidResourceException.h"

#include <iomanip>

Video::Video(std::string _type, std::string _title, std::string _author, std::string _videoLength) : Media(_type, _title, _author), videoLength(_videoLength) {
	if (_type != "video")
        throw InvalidResourceException("Creating Video object of type \"" + _type + "\" is not allowed");
}
Video::Video(const int _id, std::string _type, std::string _title, std::string _author, std::string _purchaseDate, std::stringstream& ss) : Media(_id, _type, _title, _author, _purchaseDate) {
	if (_type != "video")
        throw InvalidResourceException("Creating Video object of type \"" + _type + "\" is not allowed");
	std::getline(ss, videoLength);
}

std::string Video::print_csv() const {
	std::ostringstream oss;
	oss << id << ','
		<< type << ','
		<< title << ','
		<< author << ','
		<< purchaseDate << ','
		<< videoLength;
	return oss.str();
}
std::string Video::print_cout() const {
	std::ostringstream oss;
	oss << std::setw(6) << id << " | "
		<< std::setw(5) << std::left << type << " | "
		<< std::setw(25) << std::left << title << " | "
		<< std::setw(20) << std::left << author << " | "
		<< std::setw(13) << purchaseDate << " | "
		<< std::setw(10) << std::left << videoLength;
	return oss.str();
}

std::unique_ptr<Media> Video::clone() const {
	return std::make_unique<Video>(*this);
}