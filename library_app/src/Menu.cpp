#include "Menu.h"

#include "service/UserService.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <vector>

// Public
std::shared_ptr<Menu> Menu::get_instance(std::string userData, std::string mediaData) {
	static std::shared_ptr<Menu> instance(new Menu(userData, mediaData));
	return instance;
}

void Menu::run() { 
	// while (main_menu()); 
}

// Private
Menu::Menu(std::string& userData, std::string& mediaData) {
	userService = std::make_unique<UserService>(userData);
	mediaService = std::make_unique<MediaService>(mediaData);
}

bool Menu::main_menu() {
	std::cout
		<< "Welcome to Denton Library\n\n"
		<< "1. Log in\n"
		<< "2. Quit\n"
		<< '\n';

	const int choice = get_choice(1, 2);
	switch (choice) {
		case 1:
			if (log_in())
				user_menu();
			else
				std::cout << "Incorrect username/password.\n";
			break;
		case 2:
			std::cout << "Quitting main menu...\n";
			return false;
		default:
			std::cout << "Error: Invalid choice.\n";
	}
	std::cout << '\n';

	return true;
}
void Menu::user_menu() {
	if (user->get_type() == "patron")
		while (patron_menu());
	else if (user->get_type() == "admin")
		while (admin_menu());
	else
		std::cout << "Error getting menu for invalid user type.\n";
}
bool Menu::patron_menu() {
	std::cout
		<< "Hello " << user->get_name() << "\n\n"
		<< "1. See all available media\n"
		<< "2. Search\n"
		<< "3. See my rentals\n"
		<< "4. Renew media\n"
		<< "5. Return media\n"
		<< "6. Log out\n"
		<< '\n';

	const int choice = get_choice(1, 6);
	switch (choice) {
		case 1:
			get_all_available_media_user();
			break;
		case 2:
			// Search
			break;
		case 3:
			// See my rentals
			break;
		case 4:
			// Renew media
			break;
		case 5:
			// Return media
			break;
		case 6:
			std::cout << "Logging out...\n";
			return false;
		default:
			std::cout << "Error: Invalid choice.\n";
	}
	std::cout << '\n';

	return true;
}
bool Menu::admin_menu() {
	std::cout
		<< "Hello " << user->get_name() << "\n\n"
		<< "1. See all available media\n"
		<< "2. Search\n"
		<< "3. Add media\n"
		<< "4. Update media\n"
		<< "5. Delete media\n"
		<< "6. See all rented media\n"
		<< "7. See all transactions\n"
		<< "8. Get inventory count\n"
		<< "9. Log out\n"
		<< '\n';

	const int choice = get_choice(1, 9);
	switch (choice) {
		case 1:
			// See all available media
			break;
		case 2:
			// Search
			break;
		case 3:
			// Add media
			break;
		case 4:
			// Update media
			break;
		case 5:
			// Delete media
			break;
		case 6:
			// See all rented media
			break;
		case 7:
			// See all transactions
			break;
		case 8:
			// Get inventory count
			break;
		case 9:
			std::cout << "Logging out...\n";
			return false;
		default:
			std::cout << "Error: Invalid choice.\n";
	}
	std::cout << '\n';

	return true;
}
void Menu::rent_menu() {
	std::cout
		<< "1. Rent an item\n"
		<< "2. Go back\n"
		<< '\n';
	
	const int choice = get_choice(1, 2);
	switch (choice) {
		case 1:
			get_all_available_media_user();
			break;
		case 2:
			std::cout << "Going back...\n";
			break;
		default:
			std::cout << "Error: Invalid choice.\n";
	}
	std::cout << '\n';
}

void Menu::get_all_available_media_user() {
	std::vector<std::unique_ptr<Media>> items = mediaService->find_all();

	std::cout
		<< std::setw(6) << std::left << "ID" << " | "
		<< std::setw(5) << std::left << "Type" << " | "
		<< std::setw(20) << std::left << "Title" << " | "
		<< std::setw(30) << std::left << "Author" << " | "
		<< std::setw(13) << std::left << "Purhcase Date" << " | "
		<< std::setw(15) << std::left << "Extra1"
		<< '\n';
	std::cout << std::setw(114) << std::setfill('-') << "" << std::setfill(' ') << '\n';

	for (const auto& item : items)
		std::cout << item->print_cout() << '\n';
	std::cout << '\n';

	rent_menu();
}
void Menu::rent_item() {
	std::cout << "Enter the item's ID: ";
	int id;
	std::cin >> id;

	// Find item by id
	// If found
		// If available
			// Rent
		// Else
			// Item unavailable
	// Else
		// Item does not exist
}

int Menu::get_choice(const int lowerBound, const int upperBound) const {
	int choice;
	while (true) {
		std::cout << "Choose an option: ";
		std::cin >> choice;
		if (choice >= lowerBound && choice <= upperBound) break;
		std::cout << "Invalid choice. Please try again.\n";
	}
	std::cout << '\n';

	return choice;
}
bool Menu::log_in() {
	std::cin.ignore();
	std::cout << "Account Login\n";

	std::cout << "Enter username: ";
	std::string username;
	std::getline(std::cin, username);

	std::cout << "Enter password: ";
	std::string password;
	std::getline(std::cin, password);
	std::cout << '\n';

	user = userService->log_in(username, password);
	return user != nullptr;
}