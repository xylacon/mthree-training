#pragma once

#include <string>

class Transaction {
public:
	Transaction(const int, const int, std::string, std::string);

	int get_patron_id() const;
	int get_book_id() const;
	const std::string& get_loan_date() const;
	const std::string& get_due_date() const;

private:
	int patronId;
	int bookId;
	std::string loanDate;
	std::string dueDate;
};