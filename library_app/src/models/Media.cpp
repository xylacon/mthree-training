#include "models/Media.h"

#include <string>

#include "utility.h"

int Media::counter = 0;

Media::Media(std::string _type, std::string _title, std::string _author, std::string _purchaseDate) : id(utils::generate_id(counter)), type(_type), title(_title), author(_author), purchaseDate(_purchaseDate) {}
Media::Media(const int _id, std::string _type, std::string _title, std::string _author, std::string _purchaseDate) : id(_id), type(_type), title(_title), author(_author), purchaseDate(_purchaseDate) {
	if (_id > counter)
		counter = _id;
}

int Media::get_id() const { return id; }