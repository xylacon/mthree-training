#include "models/Audio.h"

#include "exceptions/InvalidResourceException.h"

#include <iomanip>

Audio::Audio(std::string _type, std::string _title, std::string _author, std::string _audioLength) : Media(_type, _title, _author), audioLength(_audioLength) {
	if (_type != "audio")
        throw InvalidResourceException("Creating Audio object of type \"" + _type + "\" is not allowed");
}
Audio::Audio(const int _id, std::string _type, std::string _title, std::string _author, std::string _purchaseDate, std::stringstream& ss) : Media(_id, _type, _title, _author, _purchaseDate) {
	if (_type != "audio")
        throw InvalidResourceException("Creating Audio object of type \"" + _type + "\" is not allowed");
	std::getline(ss, audioLength);
}

std::string Audio::print_csv() const {
	std::ostringstream oss;
	oss << id << ','
		<< type << ','
		<< title << ','
		<< author << ','
		<< purchaseDate << ','
		<< audioLength;
	return oss.str();
}
std::string Audio::print_cout() const {
	std::ostringstream oss;
	oss << std::setw(6) << id << " | "
		<< std::setw(5) << std::left << type << " | "
		<< std::setw(25) << std::left << title << " | "
		<< std::setw(20) << std::left << author << " | "
		<< std::setw(13) << purchaseDate << " | "
		<< std::setw(10) << std::left << audioLength;
	return oss.str();
}

std::unique_ptr<Media> Audio::clone() const {
	return std::make_unique<Audio>(*this);
}