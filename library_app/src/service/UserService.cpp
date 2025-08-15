#include "service/UserService.h"

#include "models/User.h"
#include "dao/UserDAO.h"

#include <string>
#include <iostream>
#include <memory>

UserService::UserService(std::string& filename) { dao = UserDAO::get_instance(filename); }

std::unique_ptr<User> UserService::log_in(const std::string& username, const std::string& password) const {
	return dao->find_by_username_password(username, password);
}

void UserService::add(User& user) {
	dao->insert(user.clone());
}
void UserService::update(User& user) {
	if (dao->exists(user.get_id()))
		dao->update(user.clone());
	else
		std::cout << "Update failed. User not found.\n";
}
void UserService::remove(const int id) {
	if (dao->exists(id))
		dao->remove(id);
	else
		std::cout << "Deletion failed. User not found.\n";
}

std::unique_ptr<User> UserService::find_by_id(const int id) const {
	return dao->find_by_id(id);
}
std::vector<std::unique_ptr<User>> UserService::find_all() const {
	return dao->find_all();
}