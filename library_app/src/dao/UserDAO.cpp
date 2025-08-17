#include "dao/UserDAO.h"

#include "models/User.h"
#include "models/Patron.h"
#include "models/Admin.h"

#include "exceptions/DataImportException.h"
#include "exceptions/InvalidUserException.h"
#include "exceptions/ResourceNotFoundException.h"
#include "exceptions/DuplicateResourceException.h"

#include "utility.h"

#include <fstream>
#include <sstream>
#include <iostream>

// PUBLIC
std::shared_ptr<UserDAO> UserDAO::get_instance(std::string& _filename) {
	static std::shared_ptr<UserDAO> instance(new UserDAO(_filename));
	return instance;
}

void UserDAO::insert(std::unique_ptr<User> user) {
	if (exists(user->get_username()))
		throw DuplicateResourceException("Username already exists");

	users.push_back(std::move(user));

	// Update data file
	std::ofstream file(filename, std::ios::app);
	if (!file)
		throw DataImportException("Failed to open " + filename);

	file << users.back()->print_csv() << '\n';
}
void UserDAO::update(std::unique_ptr<User> user) {
	const int id = user->get_id();
	bool found = false;
	for (auto& u : users) {
		if (u->get_id() == id) {
			u = std::move(user);
			found = true;
			break;
		}
	}

	if (!found)
		throw ResourceNotFoundException("User ID does not exist");

	save_all();
}
void UserDAO::remove(const int id) {
	bool found = false;
	for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->get_id() == id) {
            users.erase(it);
			found = true;
			break;
		}
	}

	if (!found)
		throw ResourceNotFoundException("User ID does not exist");

	save_all();
}

std::unique_ptr<User> UserDAO::find_by_id(const int id) const {
	for (const auto& user : users)
        if (user->get_id() == id)
            return user->clone();
    return nullptr;
}
std::unique_ptr<User> UserDAO::find_by_username_password(const std::string& username, const std::string& password) {
	for (const auto& user : users)
        if (user->get_username() == username && user->get_password() == password)
            return user->clone();
    return nullptr;
}
std::vector<std::unique_ptr<User>> UserDAO::find_all() const {
	std::vector<std::unique_ptr<User>> copy;
	copy.reserve(users.size());

	for (const auto& user : users)
		copy.push_back(user->clone());
	
	return copy;
}

bool UserDAO::exists(const int id) const {
	for (const auto& user : users)
        if (user->get_id() == id)
            return true;
    return false;
}
bool UserDAO::exists(const std::string& username) const {
	for (const auto& user : users)
        if (user->get_username() == username)
            return true;
    return false;
}

// PRIVATE
UserDAO::UserDAO(std::string& _filename) : filename(_filename) { load_all(); }

void UserDAO::load_all() {
	if (!utils::file_exists(filename)) {
		std::ofstream file(filename);
		file.close();
	}

	std::ifstream file(filename);
	if (!file)
		throw DataImportException("Failed to open " + filename);

	std::string line;
	std::string idStr, type, username, password, name;
	int id;

	while (std::getline(file, line)) {
		std::stringstream ss(line);

		std::getline(ss, idStr, ',');
		id = std::stoi(idStr);
		std::getline(ss, type, ',');
		std::getline(ss, username, ',');
		std::getline(ss, password, ',');
		std::getline(ss, name, ',');

		try {
			if (type == "patron")
				users.push_back(std::make_unique<Patron>(id, type, username, password, name, ss));
			else if (type == "admin")
				users.push_back(std::make_unique<Admin>(id, type, username, password, name, ss));
		} catch (const InvalidUserException& ex) {
			std::cerr << ex.what() << '\n';
		}
	}

	file.close();
}

void UserDAO::save_all() {
	std::ofstream file(filename);
	if (!file)
		throw DataImportException("Failed to open " + filename);

	for (const auto& user : users)
		file << user->print_csv() << '\n';

	file.close();
}