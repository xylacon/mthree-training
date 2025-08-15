#pragma once

#include <string>
#include <memory>

class Media {
public:
	Media(std::string, std::string, std::string, std::string);
	Media(const int, std::string, std::string, std::string, std::string);

	int get_id() const;
	std::string get_title() const;
	std::string get_author() const;
	std::string get_type() const;

	virtual std::string print_csv() const = 0;

	virtual std::unique_ptr<Media> clone() const = 0;

	virtual ~Media() = default;

protected:
	int id;
	std::string type;
	std::string title;
	std::string author;
	std::string purchaseDate;

private:
	static int counter;
};