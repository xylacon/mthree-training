#include "dao/UserDAO.h"

#include "models/User.h"
#include "models/Patron.h"
#include "models/Admin.h"

#include "utility.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

// PUBLIC
std::shared_ptr<UserDAO> UserDAO::get_instance(const std::string& _inFile, const std::string& _outFile) {
	static std::shared_ptr<UserDAO> instance(new UserDAO(_inFile, _outFile));
	return instance;
}

void UserDAO::insert(std::unique_ptr<User> user) {
	users.push_back(std::move(user));

	// Update data file
	std::ofstream file(outFile, std::ios::app);
	if (!file) {
		std::cerr << "Failed to open " << outFile << '\n';
		return;
	}

	file << users.back()->print_csv() << '\n';
}
void UserDAO::update(std::unique_ptr<User> user) {
	const int id = user->get_id();
	for (auto& u : users) {
		if (u->get_id() == id) {
			u = std::move(user);
			break;
		}
	}

	save_all();
}
void UserDAO::remove(const int id) {
	for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->get_id() == id) {
            users.erase(it);
			break;
		}
	}

	save_all();
}

std::unique_ptr<User> UserDAO::find_by_id(const int id) const {
	for (const auto& user : users)
        if (user->get_id() == id)
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

// PRIVATE
UserDAO::UserDAO(const std::string& _inFile, const std::string& _outFile) : inFile(_inFile), outFile(_outFile) {
	load_all();
}

void UserDAO::load_all() {
	if (!utils::file_exists(inFile)) {
		std::ofstream file(inFile);
		file.close();
	}

	std::ifstream file(inFile);
	if (!file) {
		std::cerr << "Failed to open " << inFile << '\n';
		return;
	}

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

		if (type == "patron")
			users.push_back(std::make_unique<Patron>(id, type, username, password, name, ss));
		else if (type == "admin")
			users.push_back(std::make_unique<Admin>(id, type, username, password, name, ss));
		else
			std::cout << "Could not read invalid user type.\n";
	}

	file.close();
}

void UserDAO::save_all() {
	std::ofstream file(outFile);
	if (!file) {
		std::cerr << "Failed to open " << outFile << '\n';
		return;
	}

	for (const auto& user : users)
		file << user->print_csv() << '\n';

	file.close();
}