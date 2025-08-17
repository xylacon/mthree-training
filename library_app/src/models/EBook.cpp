#include "models/EBook.h"

#include "exceptions/InvalidMediaException.h"

#include <iomanip>

EBook::EBook(std::string _type, std::string _title, std::string _author, std::string _downloadSize) : Media(_type, _title, _author), downloadSize(_downloadSize) {
	if (_type != "ebook")
        throw InvalidMediaException("Creating EBook object of type \"" + _type + "\" is not allowed");
}
EBook::EBook(const int _id, std::string _type, std::string _title, std::string _author, std::string _purchaseDate, std::stringstream& ss) : Media(_id, _type, _title, _author, _purchaseDate) {
	if (_type != "ebook")
        throw InvalidMediaException("Creating EBook object of type \"" + _type + "\" is not allowed");
	std::getline(ss, downloadSize);
}

std::string EBook::print_csv() const {
	std::ostringstream oss;
	oss << id << ','
		<< type << ','
		<< title << ','
		<< author << ','
		<< purchaseDate << ','
		<< downloadSize;
	return oss.str();
}
std::string EBook::print_cout() const {
	std::ostringstream oss;
	oss << std::setw(6) << id << " | "
		<< std::setw(5) << std::left << type << " | "
		<< std::setw(20) << std::left << title << " | "
		<< std::setw(30) << std::left << author << " | "
		<< std::setw(13) << purchaseDate << " | "
		<< std::setw(15) << std::left << downloadSize;
	return oss.str();
}

std::unique_ptr<Media> EBook::clone() const {
	return std::make_unique<EBook>(*this);
}