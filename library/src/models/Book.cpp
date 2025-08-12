#include "models/Book.h"

#include <string>

#include "utility.h"

int Book::counter = 0;

Book::Book(std::string _title, std::string _author, std::string _genre, const int _year) : id(utils::generate_id(counter)), title(_title), author(_author), genre(_genre), year(_year) {}

void Book::set_title(std::string _title) { title = std::move(_title); }
void Book::set_author(std::string _author) { author = std::move(_author); }
void Book::set_genre(std::string _genre) { genre = std::move(_genre); }
void Book::set_year(const int _year) { year = _year; }

int Book::get_id() const { return id; }
const std::string& Book::get_title() const { return title; }
const std::string& Book::get_author() const { return author; }
const std::string& Book::get_genre() const { return genre; }
int Book::get_year() const { return year; }

// bool Book::operator==(const Book& other) const { return id == other.id; }