#pragma once

#include "models/User.h"
#include "service/UserService.h"

#include <memory>

// Singleton
class Menu {
public:
	static std::shared_ptr<Menu> get_instance(std::string);

	// Prevent copy/assignment
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;

	void run();
	bool main_menu() const;

	int get_choice(const int, const int) const;
	bool log_in();

private:
	std::unique_ptr<User> user;
	std::unique_ptr<UserService> service;
	Menu(std::string&);
};