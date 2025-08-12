#include "Patron.h"

#include <string>

#include "utility.h"

int Patron::counter = 100000;

Patron::Patron(std::string _name) : id(utils::generate_id(counter)), name(_name) {}

void Patron::set_name(std::string _name) { name = std::move(_name); }

int Patron::get_id() const { return id; }
const std::string& Patron::get_name() const { return name; }