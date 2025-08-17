#include "service/UserService.h"

UserService::UserService(std::string& filename) { dao = UserDAO::get_instance(filename); }

void UserService::add(User& user) {
	dao->insert(user.clone());
}
void UserService::update(User& user) {
	dao->update(user.clone());
}
void UserService::remove(const int id) {
	dao->remove(id);
}

std::unique_ptr<User> UserService::find_by_id(const int id) const {
	return dao->find_by_id(id);
}
std::unique_ptr<User> UserService::find_by_login(const std::string& username, const std::string& password) const {
	return dao->find_by_username_password(username, password);
}
std::vector<std::unique_ptr<User>> UserService::find_all() const {
	return dao->find_all();
}