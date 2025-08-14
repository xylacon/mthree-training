#pragma once

#include <string>
#include <memory>

class User {
public:
	User(std::string, std::string, std::string, std::string);
	User(const int, std::string, std::string, std::string, std::string);

	int get_id() const;

	virtual std::string print_csv() const = 0;

	virtual std::unique_ptr<User> clone() const = 0;

	virtual ~User() = default;

protected:
	int id;
	std::string type;
	std::string username;
	std::string password;
	std::string name;
	
private:
	static int counter;
};