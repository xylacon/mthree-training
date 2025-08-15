#pragma once

#include "models/User.h"
#include "service/UserService.h"
#include "service/MediaService.h"

#include <memory>

// Singleton
class Menu {
public:
	static std::shared_ptr<Menu> get_instance(std::string, std::string);

	// Prevent copy/assignment
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;

	void run();

private:
	std::unique_ptr<User> user;
	std::unique_ptr<UserService> userService;
	std::unique_ptr<MediaService> mediaService;

	Menu(std::string&, std::string&);

	bool main_menu();
	void user_menu();
	bool patron_menu();
	bool admin_menu();
	void rent_menu();

	void get_all_available_media_user();
	void rent_item();

	int get_choice(const int, const int) const;
	bool log_in();
};