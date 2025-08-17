#include "models/Transaction.h"

#include "utility.h"

#include <fstream>
#include <sstream>
#include <iomanip>

Transaction::Transaction(const int _userId, const int _mediaId) : userId(_userId), mediaId(_mediaId), loanDate(utils::generate_date()), returnDate(generate_return_date(loanDate)) {}
Transaction::Transaction(const int _userId, const int _mediaId, std::string _loanDate, std::string _returnDate) : userId(_userId), mediaId(_mediaId), loanDate(_loanDate), returnDate(_returnDate) {}

void Transaction::renew_media() {
	returnDate = generate_return_date(std::time(0));
}

int Transaction::get_user_id() const { return userId; }
int Transaction::get_media_id() const { return mediaId; }

std::string Transaction::print_csv() const {
	std::ostringstream oss;
	oss << userId << ','
		<< mediaId << ','
		<< loanDate << ','
		<< returnDate;
	return oss.str();
}
std::string Transaction::print_cout() const {
	std::ostringstream oss;
	oss << std::setw(6) << userId << " | "
		<< std::setw(7) << mediaId << " | "
		<< std::setw(10) << std::left << loanDate << " | "
		<< std::setw(11) << std::left << returnDate;
	return oss.str();
}

std::unique_ptr<Transaction> Transaction::clone() const {
	return std::make_unique<Transaction>(*this);
}

std::string Transaction::generate_return_date(const std::string& date) const {
	std::tm tm{};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%m/%d/%Y"); // Convert str to time struct tm
	std::time_t t = std::mktime(&tm); // Convert tm to time_t
	t += 7 * 24 * 60 * 60; // Add 7 days

	std::ostringstream oss;
	oss << std::put_time(std::localtime(&t), "%m/%d/%Y"); // Convert back
	return oss.str();
}

std::string Transaction::generate_return_date(std::time_t t) const {
	t += 7 * 24 * 60 * 60; // Add 7 days

	std::ostringstream oss;
	oss << std::put_time(std::localtime(&t), "%m/%d/%Y"); // Convert back
	return oss.str();
}