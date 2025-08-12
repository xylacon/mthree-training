#include "models/Patron.h"

#include <string>

#include "utility.h"

int Patron::counter = 0;

Patron::Patron(std::string _name) : id(utils::generate_id(counter)), name(_name) {}
Patron::Patron(const int _id, std::string _name) : id(_id), name(_name) {
	if (_id > counter)
		counter = _id;
}

void Patron::set_name(std::string _name) { name = std::move(_name); }

int Patron::get_id() const { return id; }
const std::string& Patron::get_name() const { return name; }