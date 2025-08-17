#include "dao/TransactionDAO.h"

#include "models/Transaction.h"
#include "models/Patron.h"
#include "models/Admin.h"

#include "utility.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

// PUBLIC
std::shared_ptr<TransactionDAO> TransactionDAO::get_instance(std::string& _filename) {
	static std::shared_ptr<TransactionDAO> instance(new TransactionDAO(_filename));
	return instance;
}

void TransactionDAO::insert(std::unique_ptr<Transaction> transaction) {
	transactions.push_back(std::move(transaction));

	// Update data file
	std::ofstream file(filename, std::ios::app);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return;
	}

	file << transactions.back()->print_csv() << '\n';
}
void TransactionDAO::update(std::unique_ptr<Transaction> transaction) {
	const int userId = transaction->get_user_id();
	const int mediaId = transaction->get_media_id();
	for (auto& t : transactions) {
		if (t->get_user_id() == userId && t->get_media_id() == mediaId) {
			t = std::move(transaction);
			break;
		}
	}

	save_all();
}
void TransactionDAO::remove(const int userId, const int mediaId) {
	for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if ((*it)->get_user_id() == userId && (*it)->get_media_id() == mediaId) {
            transactions.erase(it);
			break;
		}
	}

	save_all();
}

std::unique_ptr<Transaction> TransactionDAO::find(const int userId, const int mediaId) const {
	std::vector<std::unique_ptr<Transaction>> copy;
	for (const auto& transaction : transactions)
        if (transaction->get_user_id() == userId && transaction->get_user_id() == mediaId)
            return transaction->clone();
	return nullptr;
}
std::vector<std::unique_ptr<Transaction>> TransactionDAO::find_by_user_id(const int id) const {
	std::vector<std::unique_ptr<Transaction>> copy;
	for (const auto& transaction : transactions)
        if (transaction->get_user_id() == id)
            copy.push_back(transaction->clone());
    return copy;
}
std::vector<std::unique_ptr<Transaction>> TransactionDAO::find_by_media_id(const int id) const {
	std::vector<std::unique_ptr<Transaction>> copy;
	for (const auto& transaction : transactions)
        if (transaction->get_media_id() == id)
            copy.push_back(transaction->clone());
    return copy;
}
std::vector<std::unique_ptr<Transaction>> TransactionDAO::find_all() const {
	std::vector<std::unique_ptr<Transaction>> copy;
	copy.reserve(transactions.size());

	for (const auto& transaction : transactions)
		copy.push_back(transaction->clone());
	
	return copy;
}

bool TransactionDAO::exists(const int userId, const int mediaId) const {
	for (const auto& transaction : transactions)
        if (transaction->get_user_id() == userId && transaction->get_media_id() == mediaId)
            return true;
    return false;
}
bool TransactionDAO::exists_book(const int id) const {
	for (const auto& transaction : transactions)
        if (transaction->get_media_id() == id)
            return true;
    return false;
}

// PRIVATE
TransactionDAO::TransactionDAO(std::string& _filename) : filename(_filename) { load_all(); }

void TransactionDAO::load_all() {
	if (!utils::file_exists(filename)) {
		std::ofstream file(filename);
		file.close();
	}

	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return;
	}

	std::string line;
	std::string userIdStr, mediaIdStr, loanDate, returnDate;
	int userId, mediaId;

	while (std::getline(file, line)) {
		std::stringstream ss(line);

		std::getline(ss, userIdStr, ',');
		userId = std::stoi(userIdStr);
		std::getline(ss, mediaIdStr, ',');
		mediaId = std::stoi(mediaIdStr);
		std::getline(ss, loanDate, ',');
		std::getline(ss, returnDate);

		transactions.push_back(std::make_unique<Transaction>(userId, mediaId, loanDate, returnDate));
	}

	file.close();
}

void TransactionDAO::save_all() {
	std::ofstream file(filename);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return;
	}

	for (const auto& transaction : transactions)
		file << transaction->print_csv() << '\n';

	file.close();
}