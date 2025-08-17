#include "models/Media.h"

#include "utility.h"

int Media::counter = 0;

Media::Media(std::string _type, std::string _title, std::string _author) : id(utils::generate_id(counter)), type(_type), title(_title), author(_author), purchaseDate(utils::generate_date()) {}
Media::Media(const int _id, std::string _type, std::string _title, std::string _author, std::string _purchaseDate) : id(_id), type(_type), title(_title), author(_author), purchaseDate(_purchaseDate) {
	if (_id > counter)
		counter = _id;
}

void Media::set_title(std::string _title) { title = _title; }
void Media::set_author(std::string _author) { author = _author; }

int Media::get_id() const { return id; }
std::string Media::get_title() const { return title; }
std::string Media::get_author() const { return author; }
std::string Media::get_type() const { return type; }