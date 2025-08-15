#pragma once

#include "models/Transaction.h"

#include <vector>
#include <string>
#include <memory>

// Singleton
class TransactionDAO {
public:
	static std::shared_ptr<TransactionDAO> get_instance(std::string&);

	// Prevent copy/assignment
	TransactionDAO(const TransactionDAO&) = delete;
	TransactionDAO& operator=(const TransactionDAO&) = delete;

	void insert(std::unique_ptr<Transaction>);
	void update(std::unique_ptr<Transaction>);
	void remove(const int, const int);

	std::unique_ptr<Transaction> find(const int, const int) const;
	std::vector<std::unique_ptr<Transaction>> find_by_user_id(const int) const;
	std::vector<std::unique_ptr<Transaction>> find_by_media_id(const int) const;
	std::vector<std::unique_ptr<Transaction>> find_all() const;

	bool exists(const int, const int) const;
	bool exists_book(const int) const;

private:
	std::string filename; // Data source
	std::vector<std::unique_ptr<Transaction>> transactions;

	TransactionDAO(std::string&);

	void load_all();
	void save_all();
};