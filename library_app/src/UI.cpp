#include "UI.h"

#include <iostream>
#include <iomanip>
#include <limits>

int UI::get_choice(const int lowerBound, const int upperBound) const {
	int choice;
	while (true) {
		std::cout << "Choose an option: ";
		if (std::cin >> choice) {
			if (choice >= lowerBound && choice <= upperBound) break;
			std::cout << "Invalid choice. Please try again.\n";
		} else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number.\n";
		}
	}
	std::cout << '\n';
	std::cin.ignore();

	return choice;
}

void UI::print_media(std::vector<std::unique_ptr<Media>>& items) {
	if (items.empty()) {
		std::cout << "No media to show.\n";
		return;
	}

	std::cout
		<< std::setw(6) << std::left << "ID" << " | "
		<< std::setw(5) << std::left << "Type" << " | "
		<< std::setw(25) << std::left << "Title" << " | "
		<< std::setw(20) << std::left << "Author" << " | "
		<< std::setw(13) << std::left << "Purhcase Date" << " | "
		<< std::setw(10) << std::left << "Note"
		<< '\n';
	std::cout << std::setw(94) << std::setfill('-') << "" << std::setfill(' ') << '\n';

	for (const auto& item : items)
		std::cout << item->print_cout() << '\n';
	std::cout << '\n';
}

void UI::print_transactions(std::vector<std::unique_ptr<Transaction>>& transactions) {
	if (transactions.empty()) {
		std::cout << "No media to show.\n";
		return;
	}

	std::cout
		<< std::setw(6) << std::left << "UserID" << " | "
		<< std::setw(7) << std::left << "MediaID" << " | "
		<< std::setw(10) << std::left << "Loan Date" << " | "
		<< std::setw(11) << std::left << "Return Date" << '\n';
	std::cout << std::setw(43) << std::setfill('-') << "" << std::setfill(' ') << '\n';

	for (const auto& transaction : transactions)
		std::cout << transaction->print_cout() << '\n';
	std::cout << '\n';
}