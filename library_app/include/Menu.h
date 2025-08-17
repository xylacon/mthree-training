#pragma once

#include "service/UserService.h"
#include "service/MediaService.h"
#include "service/TransactionService.h"

#include "UI.h"

#include <string>
#include <memory>
#include <vector>

class Menu {
public:
	Menu(std::string, std::string, std::string);

	void run();

private:
	UI ui;
	
	std::unique_ptr<User> user;
	std::unique_ptr<UserService> userService;
	std::unique_ptr<MediaService> mediaService;
	std::unique_ptr<TransactionService> transactionService;

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
	std::unique_ptr<Media> add_book(std::string&, std::string&, std::string&);
	std::unique_ptr<Media> add_ebook(std::string&, std::string&, std::string&);
	std::unique_ptr<Media> add_audio(std::string&, std::string&, std::string&);
	std::unique_ptr<Media> add_video(std::string&, std::string&, std::string&);
	void update_media();
	void delete_media();

	bool log_in();
	void remove_loaned_books(std::vector<std::unique_ptr<Media>>&);
};