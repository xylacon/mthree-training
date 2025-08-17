#pragma once

#include "models/User.h"

#include <vector>
#include <string>
#include <memory>

// Singleton
class UserDAO {
public:
	static std::shared_ptr<UserDAO> get_instance(std::string&);

	// Prevent copy/assignment
	UserDAO(const UserDAO&) = delete;
	UserDAO& operator=(const UserDAO&) = delete;

	void insert(std::unique_ptr<User>);
	void update(std::unique_ptr<User>);
	void remove(const int);

	std::unique_ptr<User> find_by_id(const int) const;
	std::unique_ptr<User> find_by_username_password(const std::string&, const std::string&);
	std::vector<std::unique_ptr<User>> find_all() const;

	bool exists(const int) const;
	bool exists(const std::string&) const;

private:
	std::string filename; // Data source
	std::vector<std::unique_ptr<User>> users;

	UserDAO(std::string&);

	void load_all();
	void save_all();
};