#pragma once

#include <string>

class Book {
public:
	Book(std::string, std::string, std::string, const int);

	void set_title(std::string);
	void set_author(std::string);
	void set_genre(std::string);
	void set_year(const int);

	int get_id() const;
	const std::string& get_title() const;
	const std::string& get_author() const;
	const std::string& get_genre() const;
	int get_year() const;

	// bool operator==(const Book&) const;

private:
	static int counter;

	int id;
	std::string title;
	std::string author;
	std::string genre;
	int year;
};