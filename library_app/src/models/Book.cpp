#include "models/Book.h"

#include "exceptions/InvalidResourceException.h"

#include <iomanip>

Book::Book(std::string _type, std::string _title, std::string _author, std::string _coverType) : Media(_type, _title, _author), coverType(_coverType) {
	if (_type != "book")
        throw InvalidResourceException("Creating Book object of type \"" + _type + "\" is not allowed");
}
Book::Book(const int _id, std::string _type, std::string _title, std::string _author, std::string _purchaseDate, std::stringstream& ss) : Media(_id, _type, _title, _author, _purchaseDate) {
	if (_type != "book")
        throw InvalidResourceException("Creating Book object of type \"" + _type + "\" is not allowed");
	std::getline(ss, coverType);
}

std::string Book::print_csv() const {
	std::ostringstream oss;
	oss << id << ','
		<< type << ','
		<< title << ','
		<< author << ','
		<< purchaseDate << ','
		<< coverType;
	return oss.str();
}
std::string Book::print_cout() const {
	std::ostringstream oss;
	oss << std::setw(6) << id << " | "
		<< std::setw(5) << std::left << type << " | "
		<< std::setw(25) << std::left << title << " | "
		<< std::setw(20) << std::left << author << " | "
		<< std::setw(13) << purchaseDate << " | "
		<< std::setw(10) << std::left << coverType;
	return oss.str();
}

std::unique_ptr<Media> Book::clone() const {
	return std::make_unique<Book>(*this);
}