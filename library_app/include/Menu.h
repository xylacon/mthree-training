#pragma once

#include "models/User.h"
#include "service/UserService.h"
#include "service/MediaService.h"
#include "service/TransactionService.h"

#include <memory>
#include <vector>

// Singleton
class Menu {
public:
	static std::shared_ptr<Menu> get_instance(std::string, std::string, std::string);

	// Prevent copy/assignment
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;

	void run();

private:
	std::unique_ptr<User> user;
	std::unique_ptr<UserService> userService;
	std::unique_ptr<MediaService> mediaService;
	std::unique_ptr<TransactionService> transactionService;

	Menu(std::string&, std::string&, std::string&);

	bool main_menu();
	void user_menu();
	bool patron_menu();
	bool admin_menu();
	void rent_menu();
	void search_menu();
	void loan_menu();

	void get_all_media();
	void get_all_available_media();
	void get_by_title();
	void get_by_author();
	void get_by_type();
	
	void get_loans();
	void get_all_loans();

	void rent_item();
	void renew_item();
	void return_item();

	void add_media();
	void add_book(std::string&, std::string&, std::string&);
	void add_ebook(std::string&, std::string&, std::string&);
	void add_audio(std::string&, std::string&, std::string&);
	void add_video(std::string&, std::string&, std::string&);
	void update_media();
	void delete_media();

	int get_choice(const int, const int) const;
	bool log_in();
	void print_media(std::vector<std::unique_ptr<Media>>&);
	void print_transactions(std::vector<std::unique_ptr<Transaction>>&);
	void remove_loaned_books(std::vector<std::unique_ptr<Media>>&);
};