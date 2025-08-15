#include "Menu.h"

#include "service/UserService.h"

#include <iostream>
#include <string>

// Public
std::shared_ptr<Menu> Menu::get_instance(std::string filename) {
	static std::shared_ptr<Menu> instance(new Menu(filename));
	return instance;
}

void Menu::run() {
	while(main_menu());
}
bool Menu::main_menu() const {
	std::cout
		<< "Welcome to Denton Library\n\n"
		<< "1. Log in\n"
		<< "2. Quit\n\n"
		<< "Choose an option: ";

	const int choice = get_choice(1, 2);

	switch (choice) {
		case 1:
			// Log in
			break;
		case 2:
			std::cout << "Quitting main menu...\n";
			return false;
		default:
			std::cout << "Error: Invalid choice.\n";
	}

	return true;
}

int Menu::get_choice(const int lowerBound, const int upperBound) const {
	int choice;
	while (true) {
		std::cin >> choice;
		if (choice >= lowerBound && choice <= upperBound) break;
		std::cout << "Invalid choice. Please try again.\n";
	}

	return choice;
}
bool Menu::log_in() {
	std::cout << "Enter username: ";
	std::string username;
	std::getline(std::cin, username);

	std::cout << "Enter password: ";
	std::string password;
	std::getline(std::cin, password);

	return false;
}

// Private
Menu::Menu(std::string& filename) {
	service = std::make_unique<UserService>(filename);
}