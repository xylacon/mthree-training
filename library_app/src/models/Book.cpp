#include "models/Book.h"

#include <string>
#include <sstream>
#include <iomanip>

Book::Book(std::string _type, std::string _title, std::string _author, std::string _purchaseDate, std::string _coverType) : Media(_type, _title, _author, _purchaseDate), coverType(_coverType) {}
Book::Book(const int _id, std::string _type, std::string _title, std::string _author, std::string _purchaseDate, std::stringstream& ss) : Media(_id, _type, _title, _author, _purchaseDate) {
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
		<< std::setw(20) << std::left << title << " | "
		<< std::setw(30) << std::left << author << " | "
		<< std::setw(13) << purchaseDate << " | "
		<< std::setw(15) << std::left << coverType;
	return oss.str();
}

std::unique_ptr<Media> Book::clone() const {
	return std::make_unique<Book>(*this);
}