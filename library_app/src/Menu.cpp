#include "Menu.h"

#include "models/Media.h"
#include "models/Book.h"

#include "service/UserService.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <vector>

// Public
std::shared_ptr<Menu> Menu::get_instance(std::string userData, std::string mediaData, std::string transactionData) {
	static std::shared_ptr<Menu> instance(new Menu(userData, mediaData, transactionData));
	return instance;
}

void Menu::run() { 
	while (main_menu());
}

// Private
Menu::Menu(std::string& userData, std::string& mediaData, std::string& transactionData) {
	userService = std::make_unique<UserService>(userData);
	mediaService = std::make_unique<MediaService>(mediaData);
	transactionService = std::make_unique<TransactionService>(transactionData);
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
		<< "4. Log out\n"
		<< '\n';

	const int choice = get_choice(1, 4);
	switch (choice) {
		case 1:
			get_all_available_media();
			break;
		case 2:
			search_menu();
			break;
		case 3:
			get_loans();
			break;
		case 4:
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
		<< "1. See all media\n"
		<< "2. Search\n"
		<< "3. Add media\n"
		<< "4. Update media\n"
		<< "5. Delete media\n"
		<< "6. See all rented media\n"
		<< "7. Get inventory count\n"
		<< "8. Log out\n"
		<< '\n';

	const int choice = get_choice(1, 8);
	switch (choice) {
		case 1:
			get_all_media();
			break;
		case 2:
			search_menu();
			break;
		case 3:
			add_media();
			break;
		case 4:
			update_media();
			break;
		case 5:
			delete_media();
			break;
		case 6:
			get_all_loans();
			break;
		case 7:
			std::cout << "Inventory size: " << mediaService->get_size() << '\n';
			break;
		case 8:
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
			rent_item();
			break;
		case 2:
			std::cout << "Going back...\n";
			break;
		default:
			std::cout << "Error: Invalid choice.\n";
	}
}
void Menu::search_menu() {
	std::cout
		<< "1. By title\n"
		<< "2. By author\n"
		<< "3. By type\n"
		<< "4. Go back\n"
		<< '\n';
	
	const int choice = get_choice(1, 4);
	switch (choice) {
		case 1:
			get_by_title();
			break;
		case 2:
			get_by_author();
			break;
		case 3:
			get_by_type();
			break;
		case 4:
			std::cout << "Going back...\n";
			break;
		default:
			std::cout << "Error: Invalid choice.\n";
	}
}
void Menu::loan_menu() {
	get_loans();

	std::cout
		<< "1. Renew media\n"
		<< "2. Return media\n"
		<< "3. Go back\n"
		<< '\n';
	
	const int choice = get_choice(1, 3);
	switch (choice) {
		case 1:
			renew_item();
			break;
		case 2:
			return_item();
			break;
		case 3:
			std::cout << "Going back...\n";
			break;
		default:
			std::cout << "Error: Invalid choice.\n";
	}
}

void Menu::get_all_media() {
	std::vector<std::unique_ptr<Media>> items = mediaService->find_all();
	std::cout << "All media in library...\n";
	print_media(items);
}
void Menu::get_all_available_media() {
	std::vector<std::unique_ptr<Media>> items = mediaService->find_all();
	remove_loaned_books(items);

	std::cout << "All available media in library...\n";
	print_media(items);
	if (!items.empty()) rent_menu();
}
void Menu::get_by_title() {
	std::cout << "Enter title: ";
	std::string title;
	std::getline(std::cin, title);
	std::vector<std::unique_ptr<Media>> items = mediaService->find_by_title(title);

	if (user->get_type() == "patron") {
		remove_loaned_books(items);
		print_media(items);
		if (!items.empty()) rent_menu();
	}
	else
		print_media(items);
}
void Menu::get_by_author() {
	std::cout << "Enter author: ";
	std::string author;
	std::getline(std::cin, author);
	std::vector<std::unique_ptr<Media>> items = mediaService->find_by_author(author);
	
	if (user->get_type() == "patron") {
		remove_loaned_books(items);
		print_media(items);
		if (!items.empty()) rent_menu();
	}
	else
		print_media(items);
}
void Menu::get_by_type() {
	std::cout << "Enter type: ";
	std::string type;
	std::getline(std::cin, type);
	std::vector<std::unique_ptr<Media>> items = mediaService->find_by_title(type);

	if (user->get_type() == "patron") {
		if (type == "book")
			remove_loaned_books(items);
		print_media(items);
		if (!items.empty()) rent_menu();
	}
	else
		print_media(items);
}

void Menu::get_loans() {
	std::vector<std::unique_ptr<Transaction>> transactions = transactionService->find_by_user_id(user->get_id());

	std::cout << "Your current loans\n";
	print_transactions(transactions);
}
void Menu::get_all_loans() {
	std::vector<std::unique_ptr<Transaction>> transactions = transactionService->find_all();

	std::cout << "All current loans\n";
	print_transactions(transactions);
}

void Menu::rent_item() {
	std::cout << "Enter the item's ID: ";
	int mediaId;
	std::cin >> mediaId;

	std::unique_ptr<Media> media = mediaService->find_by_id(mediaId);

	if (media == nullptr) {
		std::cout << "Item not found.\n";
		return;
	}

	if (media->get_type() == "book" && transactionService->exists_book(mediaId)) {
		std::cout << "Book is already loaned out.\n";
		return;
	}

	Transaction transaction(user->get_id(), mediaId);
	if (transactionService->add(transaction))
		std::cout << "Item checked out successfully.\n";
	else 
		std::cout << "You already have this item on loan.\n";
}
void Menu::renew_item() {
	std::cout << "Enter the item's ID: ";
	int mediaId;
	std::cin >> mediaId;

	std::unique_ptr<Transaction> transaction = transactionService->find(user->get_id(), mediaId);

	if (transaction == nullptr) {
		std::cout << "Item not found.\n";
		return;
	}

	transaction->renew_media();

	if (transactionService->update(*transaction))
		std::cout << "Item renewed successfully.\n";
	else 
		std::cout << "Error renewing item.\n";
}
void Menu::return_item() {
	std::cout << "Enter the item's ID: ";
	int mediaId;
	std::cin >> mediaId;

	if (transactionService->remove(user->get_id(), mediaId))
		std::cout << "Item returned successfully.\n";
	else 
		std::cout << "Error returning item.\n";
}

void Menu::add_media() {
	std::cout << "Add media...\n";

	std::cout << "Enter title: ";
	std::string title;
	std::getline(std::cin, title);

	std::cout << "Enter author: ";
	std::string author;
	std::getline(std::cin, author);

	while (true) {
		std::cout << "Enter media type (book, ebook, audio, video): ";
		std::string type;
		std::getline(std::cin, type);
		if (type == "book") {
			add_book(type, title, author);
		} else if (type == "ebook") {
			add_ebook(type, title, author);
		} else if (type == "audio") {
			add_audio(type, title, author);
		} else if (type == "video") {
			add_video(type, title, author);
		} else {
			std::cout << "Invalid type.\n";
			continue;
		}

		break;
	}
}
void Menu::add_book(std::string& type, std::string& title, std::string& author) {
	std::cout << "Enter cover type (ex: hard): ";
	std::string coverType;
	std::getline(std::cin, coverType);

	Book book(type, title, author, coverType);
}
void Menu::add_ebook(std::string& type, std::string& title, std::string& author) {
	std::cout << "Enter download size (ex: 50 mb): ";
	std::string downloadSize;
	std::getline(std::cin, downloadSize);
}
void Menu::add_audio(std::string& type, std::string& title, std::string& author) {
	std::cout << "Enter audio length (ex: 4 hr): ";
	std::string audioLength;
	std::getline(std::cin, audioLength);
}
void Menu::add_video(std::string& type, std::string& title, std::string& author) {
	std::cout << "Enter video length (ex: 2 hr): ";
	std::string videoLength;
	std::getline(std::cin, videoLength);
}
void Menu::update_media() {
	std::cout << "Enter the item's ID: ";
	int mediaId;
	std::cin >> mediaId;

	std::unique_ptr<Media> item = mediaService->find_by_id(mediaId);

	if (item == nullptr) {
		std::cout << "Item not found.\n";
		return;
	}

	std::cout << "Enter new title: ";
	std::string title;
	std::getline(std::cin, title);

	std::cout << "Enter new author: ";
	std::string author;
	std::getline(std::cin, author);

	item->set_title(title);
	item->set_author(author);

	if (mediaService->update(*item))
		std::cout << "Item updated successfully.\n";
	else 
		std::cout << "Error updating item.\n";
}
void Menu::delete_media() {
	std::cout << "Delete media...\n";
	std::cout << "Enter the item's ID: ";
	int mediaId;
	std::cin >> mediaId;

	if (mediaService->exists(mediaId)) {
		std::cout << "Item does not exist.\n";
		return;
	}

	if (!transactionService->find_by_media_id(mediaId).empty()) {
		std::cout << "Cannot delete, item is on loan.\n";
		return;
	}

	mediaService->remove(mediaId);
	std::cout << "Item removed successfully.\n";
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
	std::cin.ignore();

	return choice;
}
bool Menu::log_in() {
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
void Menu::print_media(std::vector<std::unique_ptr<Media>>& items) {
	if (items.empty()) {
		std::cout << "No media to show.\n";
		return;
	}

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
}
void Menu::print_transactions(std::vector<std::unique_ptr<Transaction>>& transactions) {
	if (transactions.empty()) {
		std::cout << "No media to show.\n";
		return;
	}

	std::cout
		<< std::setw(6) << std::left << "UserID" << " | "
		<< std::setw(7) << std::left << "MediaID" << " | "
		<< std::setw(10) << std::left << "Loan Date" << " | "
		<< std::setw(11) << std::left << "Return Date" << '\n';
	std::cout << std::setw(42) << std::setfill('-') << "" << std::setfill(' ') << '\n';

	for (const auto& transaction : transactions)
		std::cout << transaction->print_cout() << '\n';
	std::cout << '\n';
}
void Menu::remove_loaned_books(std::vector<std::unique_ptr<Media>>& items) {
	auto it = items.begin();
	while (it != items.end()) {
		if ((*it)->get_type() == "book" && transactionService->exists_book((*it)->get_id()))
			it = items.erase(it);
		else
			++it;
	}
}