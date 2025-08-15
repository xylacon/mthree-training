#pragma once

#include <string>
#include <memory>

class Transaction {
public:
	Transaction(const int, const int);
	Transaction(const int, const int, std::string, std::string);

	void renew_media();

	int get_user_id() const;
	int get_media_id() const;

	std::string print_csv() const;
	std::string print_cout() const;

	std::unique_ptr<Transaction> clone() const;

private:
	int userId;
	int mediaId;
	std::string loanDate;
	std::string returnDate;

	std::string generate_return_date(const std::string&) const;
};