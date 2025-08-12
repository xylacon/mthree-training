#pragma once

#include <string>

class Patron {
public:
	Patron(std::string);

	void set_name(std::string);

	int get_id() const;
	const std::string& get_name() const;

private:
	static int counter;
	
	int id;
	std::string name;
};